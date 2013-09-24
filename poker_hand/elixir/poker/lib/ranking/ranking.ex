defmodule Poker.Ranking do

  def rank ({player, hand}) do
    hand
    |> Enum.sort
    |> Enum.reverse
    |> do_rank
  end

  defp do_rank(hand) do
    find_rank(hand, [
      &straight_flush?/1,
      &flush?/1,
      &straight?/1
    ])
  end

  defp find_rank(hand, [ ranker | funcs ]) do
    case ranker.(hand) do
      nil -> find_rank(hand, funcs)
      found -> found
    end
  end

  defp find_rank(hand, []) do
    {:high_card, hand}
  end

  defp straight_flush?(hand) do
    is_flush = flush?(hand)
    is_straight = straight?(hand)

    case {is_flush, is_straight} do
      {nil, _} -> nil
      {_, nil} -> nil
      {{:flush, _tieBreaker}, {:straight, tieBreaker}} ->
        {:straight_flush, tieBreaker}
    end
  end

  defp flush?(hand) do
    [first | rest] = Enum.map(hand, fn({_face, suit}) -> suit end)

    if Enum.all?(rest, &1 == first) do
      {face, _suit} = Enum.first hand
      {:flush, face}
    end
  end

  defp straight?(hand) do
    sequential = Enum.map(hand, fn({face, _suit}) -> face end)
                  |> Enum.chunks(2, 1)
                  |> Enum.reduce(true, fn([first, second], acc) ->
                      acc and (first - second == 1)
                     end)

    if sequential do
      {face, _suit} = Enum.first hand
      {:straight, face}
    end
  end
end
