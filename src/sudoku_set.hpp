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
public:
   using set_t = uint_fast16_t; 
   using value_t = uint_fast8_t;

private:
   // static const std::array<set_t, 10> set_values;
   set_t value_set = 0;
   static constexpr std::array<sudoku_set::set_t, 10> set_values { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

public:

   class iterator {
   static constexpr std::array<uint_fast8_t, 10> values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   public:
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = uint_fast8_t;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using reference = const value_type&;

      iterator(set_t& d, std::size_t pos) : current(pos), data(d) {
         while((current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
      }
      iterator(const iterator&) = default;
      iterator& operator=(const iterator&) = default;
      ~iterator() = default;

      reference operator*() const { return values[current]; }
      pointer operator->() const {return &(values[current]); }

      iterator& operator++() 
      {
         ++current; 
         while( (current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
         return *this;
      }

      iterator operator++(int n)
      {
         iterator tmp(*this); 
         ++(*this); 
         return tmp;
      }

      iterator& operator--()
      {
         --current;
         while( ( current != 0) && ((data & set_values[current]) != set_values[current])) { --current; }
         return *this;
      }
      iterator operator--(int n)
      {
         iterator tmp(*this); 
         --(*this); 
         return tmp;
      }

      bool operator==(const iterator& other) const { return current == other.current; }
      bool operator!=(const iterator& other) const { return !(*this == other); }


   private:
      std::size_t current {0};
      uint_fast16_t& data;
   };

   class const_iterator {
   static constexpr std::array<uint_fast8_t, 10> values {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   public:
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = const uint_fast8_t;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using reference = const value_type&;

      const_iterator(const set_t& d, std::size_t pos) : current(pos), data(d) {
                  while((current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
      }
      const_iterator(const const_iterator&) = default;
      const_iterator& operator=(const const_iterator&) = default;
      ~const_iterator() = default;

      reference operator*() const { return values[current]; }
      pointer operator->() const {return &(values[current]); }

      const_iterator& operator++() 
      {
         ++current; 
         while( (current != 10) && ((data & set_values[current]) != set_values[current])) { ++current; }
         return *this;
      }

      const_iterator operator++(int n)
      {
         const_iterator tmp(*this); 
         ++(*this); 
         return tmp;
      }

      const_iterator& operator--()
      {
         --current;
         while( ( current != 0) && ((data & set_values[current]) != set_values[current])) { --current; }
         return *this;
      }
      const_iterator operator--(int n)
      {
         const_iterator tmp(*this); 
         --(*this); 
         return tmp;
      }

      bool operator==(const const_iterator& other) const { return current == other.current; }
      bool operator!=(const const_iterator& other) const { return !(*this == other); }

   private:
      std::size_t current {0};
      const uint_fast16_t& data;
   };

   sudoku_set() = default;
   sudoku_set(const sudoku_set& other) = default;
   sudoku_set(sudoku_set&& other) = default;
   sudoku_set& operator=(const sudoku_set& other) = default;
   sudoku_set& operator=(sudoku_set&& other) = default;
   ~sudoku_set() = default;

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

   std::size_t size() { return std::popcount(value_set); }

   bool operator==(const sudoku_set& other) const { return value_set == other.value_set; }
   bool operator!=(const sudoku_set& other) const {  return value_set != other.value_set; }

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

   set_t get_value() { return value_set; }

};

std::ostream& operator<<(std::ostream& os, const sudoku_set& set);
