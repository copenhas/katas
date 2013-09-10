defmodule Poker.Ranking do

  def rank ({player, hand}) do
    hand
    |> Enum.sort
    |> Enum.reverse
    |> do_rank
  end

  defp do_rank(hand) do
    nil
     |> straight_flush?(hand)
     |> flush?(hand)
     |> straight?(hand)
     |> no_rank?(hand)
  end

  defp no_rank?(nil, hand) do
    {:no_rank, nil}
  end

  defp no_rank?(rank, hand) when is_tuple rank do
    rank
  end

  defp straight_flush?(nil, hand) do
    is_flush = flush?(nil, hand)
    is_straight = straight?(nil, hand)

    case {is_flush, is_straight} do
      {nil, _} -> nil
      {_, nil} -> nil
      {{:flush, _tieBreaker}, {:straight, tieBreaker}} ->
        {:straight_flush, tieBreaker}
    end
  end

  defp straight_flush?(rank, hand) do
    rank
  end

  defp flush?(nil, hand) do
    [first | rest] = Enum.map(hand, fn({_face, suit}) -> suit end)

    if Enum.all?(rest, &1 == first) do
      {face, _suit} = Enum.first hand
      {:flush, face}
    end
  end

  defp flush?(rank, hand) do
    rank
  end

  defp straight?(nil, hand) do
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

  defp straight?(rank, hand) do
    rank
  end
end
