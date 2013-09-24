defmodule Poker.Ranking do
  alias Poker.Card

  def rank ({player, hand}) do
    hand
    |> Enum.sort
    |> Enum.reverse
    |> group_cards
    |> do_rank
  end

  defp group_cards(hand) do
    hand 
    |> group_by_face
    |> sort_by_count_then_face
  end

  defp group_by_face(hand) do
    hand
    |> Enum.reduce(HashDict.new, fn({face, suit}, groups) ->
         Dict.update(groups, face, [suit], fn(suits) -> [ suit | suits ] end)
       end)
    |> Dict.to_list
  end

  defp sort_by_count_then_face(groups) do
    Enum.sort(groups, fn({face1, suit1}, {face2, suit2}) ->
      case {Enum.count(suit1), Enum.count(suit2)} do
        {count1, count2} when count1 == count2 -> face1 > face2
        {count1, count2} -> count1 > count2
      end
    end)
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
    {:high_card, tiebreaker(hand)}
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
    [first | rest] = Enum.flat_map(hand, fn({_face, suits}) -> suits end)

    if Enum.all?(rest, &1 == first) do
      {:flush, tiebreaker(hand)}
    end
  end

  defp straight?(hand) do
    ace_high_straight = Enum.map(hand, fn({face, _suit}) -> face end)
    [ ace | rest ] = ace_high_straight
    ace_low_straight = if (ace == Card.value(:ace)), do: rest ++ [1]

    if is_sequential?(ace_high_straight) or is_sequential?(ace_low_straight) do
      {:straight, tiebreaker(hand)}
    end
  end

  defp is_sequential?(nil) do
    false
  end

  defp is_sequential?(list) when is_list(list) do
    list
    |> Enum.chunks(2, 1)
    |> Enum.reduce(true, fn([first, second], acc) ->
        acc and (first - second == 1)
       end)
  end

  defp tiebreaker(groups) do
    groups
    |> Enum.map(fn({face, _suits}) -> face end)
    |> Enum.sort(fn(f1, f2) -> f1 > f2 end)
  end
end
