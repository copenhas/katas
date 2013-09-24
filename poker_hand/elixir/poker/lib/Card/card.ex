defmodule Poker.Card do
  def value(face) when is_atom(face) or is_integer(face) do
    case face do
      :ace -> 14
      :king -> 13
      :queen -> 12
      :jack -> 11
      face -> face
    end
  end
end
