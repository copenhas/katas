defmodule Poker do
  alias Poker.Parse
  alias Poker.Ranking

  def simulate(str) do
    str
    |> Parse.round
    |> Ranking.rank_round
    |> sort
    |> winner
  end

  def sort(players) do
    Enum.sort(players, fn({_, _, {rank1, tieBreaker1}}, {_, _, {rank2, tieBreaker2}}) ->
      rval1 = Ranking.rank_value rank1
      rval2 = Ranking.rank_value rank2

      case {rval1, rval2} do
        {rval1, rval2} when rval1 == rval2 -> tieBreaker1 > tieBreaker2
        {rval1, rval2} -> rval1 > rval2
      end
    end)
  end

  def winner(players) do
    {player, _, {rank, _}} = Enum.first players
    "#{player} won with a #{rank}"
  end
end
