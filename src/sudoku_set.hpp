#pragma once 

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>

class sudoku_set
{
   using set_t = uint_fast16_t; 
   using value_t = uint_fast8_t;

private:
   template<typename T>
   class set_iterator;
   using iterator = set_iterator<value_t>;
   using const_iterator = set_iterator<const value_t>;

   // static const std::array<set_t, 10> set_values;
   set_t value_set = 0;
   static constexpr std::array<sudoku_set::set_t, 10> set_values { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
   static constexpr std::array<std::size_t, 256> pop_count { 
      0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
   };

public:



   sudoku_set() = default;
   sudoku_set(const sudoku_set& other) = default;
   sudoku_set(sudoku_set&& other) = default;
   sudoku_set& operator=(const sudoku_set& other) = default;
   sudoku_set& operator=(sudoku_set&& other) = default;
   ~sudoku_set() = default;

   sudoku_set(set_t v) : value_set(v) { }

   // initializer list constructor 

   sudoku_set(std::initializer_list<uint_fast8_t> list) {
      value_set = 0;
      for(const auto& v : list) {
         value_set |= set_values[v];
      }
   }

   void insert(value_t n) { value_set = value_set | set_values[n]; }
   void erase(value_t n) { value_set = value_set & ~set_values[n]; }
   void clear() { value_set = 0; }
   bool contains(value_t n) { return (value_set & set_values[n]) == set_values[n]; }

   // std::size_t size() { return std::popcount(value_set); }

   std::size_t size() { 
      return pop_count[value_set & 0xFF] + pop_count[value_set >> 8];
   }

   bool operator==(const sudoku_set& other) const { return value_set == other.value_set; }
   bool operator!=(const sudoku_set& other) const {  return value_set != other.value_set; }
   
   sudoku_set operator&(const sudoku_set& other) const { 
      sudoku_set x(value_set & other.value_set);
      return x;
   }

   sudoku_set operator|(const sudoku_set& other) const {
      sudoku_set x(value_set | other.value_set);
      return x;
   }

   iterator begin() { return iterator(value_set, 0); }
   iterator end() { return iterator(value_set, 10); }
   const_iterator cbegin() const { return const_iterator(value_set, 0); }
   const_iterator cend() const { return const_iterator(value_set, 10); }

   std::string to_string() const {
      std::ostringstream os;
      os << "{ ";
      for(auto i = 0; i < 10; i++) {
         if(value_set & set_values[i] == set_values[i]) {
            os << i << ", ";
         }
      }
      os << "}";
      return os.str();
   };

   // Non-std::set methods 

   set_t get_value() { return value_set; }
   bool includes(const sudoku_set& other) { return (value_set & other.value_set) == other.value_set; }
   void remove(const sudoku_set& other) {
      value_set = value_set & ~other.value_set;
   }


private:
   template<typename T>
   class set_iterator {
   static constexpr std::array<T, 10> values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   public:
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = T;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using reference = const value_type&;

      // we need to know the type of set_t we get, whether it's const or not. 

      using set_t_t = std::conditional_t<std::is_const_v<T>, const set_t&, set_t&>;
      // using set_type = std::conditional_t<std::is_const_v<T>, const float, float>;

      set_iterator(set_t_t d, std::size_t pos) : current(pos), data(d) {
         while((current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
      }
      set_iterator(const set_iterator&) = default;
      set_iterator& operator=(const set_iterator&) = default;

      ~set_iterator() = default;

      reference operator*() const { return values[current]; }
      pointer operator->() const {return &(values[current]); }

      set_iterator& operator++() 
      {
         ++current; 
         while( (current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
         return *this;
      }

      set_iterator operator++(int n)
      {
         set_iterator tmp(*this); 
         ++(*this); 
         return tmp;
      }

      set_iterator& operator--()
      {
         --current;
         while( ( current != 0) && ((data & set_values[current]) != set_values[current])) { --current; }
         return *this;
      }
      set_iterator operator--(int n)
      {
         set_iterator tmp(*this); 
         --(*this); 
         return tmp;
      }

      bool operator==(const set_iterator& other) const { return current == other.current; }
      bool operator!=(const set_iterator& other) const { return !(*this == other); }


   private:
      std::size_t current {0};
      set_t_t data;
   };
};

// std::ostream& operator<<(std::ostream& os, const sudoku_set& set);

inline std::ostream& operator<<(std::ostream& os, const sudoku_set& set)
{
   os << set.to_string(); 
   return os;
}