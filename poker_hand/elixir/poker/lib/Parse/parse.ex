defmodule Poker.Parse do
  def round (str) do
    String.split(str, "  ")
    |> Enum.map(player(&1))
  end

  def player (str) do
    [player_name, hand] = String.split(str, ":")
    cards = String.split(hand, " ") 
            |> Enum.filter(&1 != "")

    {player_name, Enum.map(cards, card(&1))}
  end

  def card(str) do
    {face(String.at(str, 0)),
     suit(String.at(str, 1))}
  end

  defp face(char) do
    case char do
      "2" -> 2
      "3" -> 3
      "4" -> 4
      "5" -> 5
      "6" -> 6
      "7" -> 7
      "8" -> 8
      "9" -> 9
      "T" -> 10
      "J" -> 11
      "Q" -> 12
      "K" -> 13
      "A" -> 14
    end
  end

  defp suit(char) do
    case char do
      "C" -> :clubs
      "D" -> :diamonds
      "S" -> :spades
      "H" -> :hearts
    end
  end
end
