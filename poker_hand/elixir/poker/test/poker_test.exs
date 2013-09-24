defmodule PokerTest do
  use ExUnit.Case

  test "can parse a player and hand" do
    player = Poker.Parse.player "player1: 2C 8D KS TH 6S"

    assert player == {"player1", [{2, :clubs},
                                  {8, :diamonds},
                                  {13, :spades},
                                  {10, :hearts},
                                  {6, :spades}]}
  end

  test "can parse a round on a line" do
    players = Poker.Parse.round "player1: 2C 8D KS TH 6S  player2: 3C 3H 4S 8C AH"

    assert players == [{"player1", [{2, :clubs},
                                    {8, :diamonds},
                                    {13, :spades},
                                    {10, :hearts},
                                    {6, :spades}]},
                       {"player2", [{3, :clubs},
                                    {3, :hearts},
                                    {4, :spades},
                                    {8, :clubs},
                                    {14, :hearts}]}]

  end

  test "ranking can match a straight flush" do
    rank = Poker.Ranking.rank {"player2", [{3, :hearts},
                                           {4, :hearts},
                                           {5, :hearts},
                                           {6, :hearts},
                                           {7, :hearts}]}

    assert rank == {:straight_flush, [7, 6, 5, 4, 3]}
  end

  test "ranking can match a straight" do
    rank = Poker.Ranking.rank {"player2", [{3, :clubs},
                                           {4, :hearts},
                                           {5, :spades},
                                           {6, :clubs},
                                           {7, :hearts}]}

    assert rank == {:straight, [7, 6, 5, 4, 3]}
  end

  test "ranking can match a straight with ace at the beginning" do
    rank = Poker.Ranking.rank {"player2", [{2, :clubs},
                                           {3, :hearts},
                                           {4, :spades},
                                           {5, :clubs},
                                           {14, :hearts}]}

    assert rank == {:straight, [14, 5, 4, 3, 2]}
  end

  test "ranking can match a flush" do
    rank = Poker.Ranking.rank {"player2", [{3, :clubs},
                                           {4, :clubs},
                                           {8, :clubs},
                                           {6, :clubs},
                                           {10, :clubs}]}

    assert rank == {:flush, [10, 8, 6, 4, 3]}
  end
end
