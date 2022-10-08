#include <vector>
#include <algorithm>
#include <queue>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <optional>

class Solution {
public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    Sudoku sudoku(board);
    sudoku.Solve();
    board = sudoku.GetSolution();
  }

private:
  class Sudoku {
   public:
    static const char kEmptyCell = '.';
    static const size_t N = 3;  // Grid side size
    static const size_t N2 = N * N;

    struct Cell {
      size_t x;
      size_t y;
      size_t value;
    };

    struct Constraint {
      Constraint() = default;

      Constraint(const std::shared_ptr<std::queue<Cell>>& updates_queue,
                 std::pair<size_t, size_t>* new_constraint_cells) :
          updates_queue{updates_queue} {
        std::copy(new_constraint_cells, new_constraint_cells + Sudoku::N2, constraint_cells);
      }

      bool Add(const Cell& cell) {
        if (!CanAdd(cell)) return false; 
        filled_cells[cell.value] = cell;
        filled_cells_count += 1;

        TryUpdateQueue();
        return true;
      }

      void Remove(const Cell& cell) {
        filled_cells[cell.value] = std::nullopt;
        filled_cells_count -= 1;
      }
      
      bool CanAdd(const Cell& cell) {
        return !filled_cells[cell.value].has_value();
      }

      void TryUpdateQueue() {
        if (filled_cells_count != Sudoku::N2 - 1) {
          return;
        }

        Cell cell_to_add;
        for (size_t value = 1; value <= Sudoku::N2; value++) {
          if (!filled_cells[value].has_value()) {
            cell_to_add.value = value;
            return;
          } 
        }

        auto empty_cells = GetEmptyCells();
        if (empty_cells.empty()) {
          throw std::runtime_error(
            "Filled cells != N2 - 1, but there are no empty cells");
        }
        cell_to_add.x = empty_cells[0].first;
        cell_to_add.y = empty_cells[0].second;

        updates_queue->push(cell_to_add);
      }

      bool IsFull() {
        return filled_cells_count == Sudoku::N2;
      }

      std::vector<std::pair<size_t, size_t>> GetEmptyCells() {
        std::vector<std::pair<size_t, size_t>> result; 
        for (auto& constraint_cell: constraint_cells) {
          bool found = false;
          for (size_t value = 1; value <= Sudoku::N2; value++) {
            if (filled_cells[value].has_value()) {
              auto& cell = *filled_cells[value];
              if (std::make_pair(cell.x, cell.y) == constraint_cell) {
                found = true;
              }
            }
          }
          if (!found) {
            result.push_back(constraint_cell);
          }
        } 
        return result;
      }

      std::vector<Cell> GetFilledCells() {
        std::vector<Cell> result;
        result.reserve(Sudoku::N2);
        for (size_t value = 1; value <= N2; value++) {
          if (filled_cells[value].has_value()) {
            result.push_back(*filled_cells[value]);
          }
        }
        return result;
      }

      std::optional<Cell> filled_cells[N2 + 1];
      size_t filled_cells_count = 0;
      std::shared_ptr<std::queue<Cell>> updates_queue;
      std::pair<size_t, size_t> constraint_cells[Sudoku::N2];
    };

  public:
    Sudoku(const std::vector<std::vector<char>>& board)
        : updates_queue_{std::make_shared<std::queue<Cell>>()} {
      std::vector<std::pair<size_t, size_t>> columns_cells[N2], rows_cells[N2], squares_cells[N2];
      for (size_t x = 0; x < N2; x++) {
        for (size_t y = 0; y < N2; y++) {
          columns_cells[y].emplace_back(x, y);
          rows_cells[x].emplace_back(x, y);
          size_t sx = x / N, sy = y / N;
          squares_cells[sx * N + sy].emplace_back(x, y);
        }
      }

      for (size_t i = 0; i < N2; i++) {
        columns_[i] = Constraint(updates_queue_, &columns_cells[i][0]);
        rows_[i] = Constraint(updates_queue_, &rows_cells[i][0]);
        squares_[i] = Constraint(updates_queue_, &squares_cells[i][0]);
      }

      for (size_t x = 0; x < N2; x++) {
        for (size_t y = 0; y < N2; y++) {
          if (board[x][y] != kEmptyCell) {
            Add({x, y, static_cast<size_t>(board[x][y] - '0')});
          }
        }
      }
    }

    bool Solve() {
      while (!IsFull()) {
        while (!updates_queue_->empty()) {
          if (!Add(updates_queue_->front())) {
            return false;
          }
        }

        if (!IsFull() && !GuessNextCell()) {
          return false;
        }
      }

      return true;
    }

    std::vector<std::vector<char>> GetSolution() {
      std::vector<std::vector<char>> solution;
      solution.reserve(N2);
      for (auto& row: rows_) {
        std::vector<char> filled_row(N2, '.');
        for (auto& cell: row.GetFilledCells()) {
          filled_row[cell.y] = '0' + cell.value;
        }
        solution.push_back(std::move(filled_row));
      } 
      return solution;
    }

   private:
    bool IsFull() {
      return full_constraints_ == 3 * N2;
    }

    bool Add(const Cell& cell) {
      bool is_added = true;
      for (auto constraint_ptr: CellConstraints(cell)) {
        full_constraints_ -= constraint_ptr->IsFull();
        is_added = is_added && constraint_ptr->Add(cell);
        full_constraints_ += constraint_ptr->IsFull();
      }
      return is_added; 
    }

    void Remove(const Cell& cell) {
      for (auto constraint_ptr: CellConstraints(cell)) {
        full_constraints_ -= constraint_ptr->IsFull();
        constraint_ptr->Remove(cell);
        full_constraints_ += constraint_ptr->IsFull();
      } 
    }

    bool CanAdd(const Cell& cell) {
      bool can_add = true;
      for (auto constraint_ptr: CellConstraints(cell)) {
        can_add = can_add && constraint_ptr->CanAdd(cell);
      }
      return can_add;
    }

    std::vector<Constraint*> CellConstraints(const Cell& cell) {
      size_t sx = cell.x / N, sy = cell.y / N;
      return {
        &columns_[cell.y],
        &rows_[cell.x],
        &squares_[sx * N + sy]
      };
    } 

    bool GuessNextCell() {
      for (auto& row: rows_) {
        for (auto& empty_cell: row.GetEmptyCells()) {
          for (size_t value = 1; value <= N2; value++) {
            Cell next_cell{empty_cell.first, empty_cell.second, value};
            if (CanAdd(next_cell)) {
              Add(next_cell);
              if (Solve()) {
                return true;
              } else {
                Remove(next_cell);
                std::queue<Cell>().swap(*updates_queue_);
              }
            }
          }
          return false;
        }
      }

      return false;
    }

   private:
    Constraint columns_[N2];
    Constraint rows_[N2];
    Constraint squares_[N2];
    size_t full_constraints_ = 0; 
    std::shared_ptr<std::queue<Cell>> updates_queue_;
  };
};