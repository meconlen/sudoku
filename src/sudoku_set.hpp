#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>

class sudoku_set
{
public:

   class iterator {
   public:
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = uint_fast8_t;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using reference = const value_type&;

      iterator(std::array<bool, 10>& d, std::size_t pos) : current(pos), data(d) {
         while((current != 10) && (data[current] != true)) { current++; }
      }
      iterator(const iterator&) = default;
      iterator& operator=(const iterator&) = default;
      ~iterator() = default;

      reference operator*() const { return values[current]; }
      pointer operator->() const {return &(values[current]); }

      iterator& operator++() 
      {
         ++current; 
         while( (current != 10) && (data[current] != true)) { current++; }
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
         while( ( current != 0) && data[current] != true) { current--; }
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
      std::array<bool, 10>& data;

      // this is a bit of a hack
      static const std::array<uint_fast8_t, 10> values;
   };

   class const_iterator {
   public:
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type = const uint_fast8_t;
      using difference_type = std::ptrdiff_t;
      using pointer = const value_type*;
      using reference = const value_type&;

      const_iterator(const std::array<bool, 10>& d, std::size_t pos) : current(pos), data(d) {
                  while((current != 10) && (data[current] != true)) { current++; }
      }
      const_iterator(const const_iterator&) = default;
      const_iterator& operator=(const const_iterator&) = default;
      ~const_iterator() = default;

      reference operator*() const { return values[current]; }
      pointer operator->() const {return &(values[current]); }

      const_iterator& operator++() 
      {
         ++current; 
         while( (current != 10) && (data[current] != true)) { current++; }
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
         while( ( current != 0) && data[current] != true) { current--; }
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
      const std::array<bool, 10>& data;

      // this is a bit of a hack
      static const std::array<uint_fast8_t, 10> values;
   };

   using value_t = uint_fast8_t;
   
   sudoku_set() = default;
   sudoku_set(const sudoku_set& other) = default;
   sudoku_set(sudoku_set&& other) = default;
   sudoku_set& operator=(const sudoku_set& other) = default;
   sudoku_set& operator=(sudoku_set&& other) = default;
   ~sudoku_set() = default;

   // initializer list constructor 

   sudoku_set(std::initializer_list<uint_fast8_t> list) {
      value_set = empty_set;
      for(const auto& v : list) {
         value_set[v] = true;
      }
   }

   // we need 

   void insert(value_t n) { value_set[n] = true; }
   void erase(value_t n) { value_set[n] = false; }
   void clear() { value_set = empty_set; }
   bool contains(value_t n) { return value_set[n]; }

   std::size_t size() {
      std::size_t count = 0; 
      for(auto i = 0; i < 10; i++) { if (value_set[i]) count++; }
      return count;
   }

   bool operator==(const sudoku_set& other) const { 
      for(auto i = 0; i < 10; i++) {
         if(value_set[i] != other.value_set[i]) {
            return false;
         }
      }
      return true;
   }
   bool operator!=(const sudoku_set& other) const { 
      for(auto i = 0; i < 10; i++) {
         if(value_set[i] != other.value_set[i]) {
            std::cout << "value_set[" << i << "] = " << value_set[i] << ", other.value_set[" << i << "] = " << other.value_set[i] << std::endl; 
            return true;
         }
      }
      return false;

   }

   iterator begin() { return iterator(value_set, 0); }
   iterator end() { return iterator(value_set, 10); }
   const_iterator cbegin() const { return const_iterator(value_set, 0); }
   const_iterator cend() const { return const_iterator(value_set, 10); }


private:
   // there's spots where we need to insert 0 easily. 
   // we should check later if it's faster to insert/remote 0 or if it's faster to ignore 0 

   static const std::array<bool, 10> empty_set;
   std::array<bool, 10> value_set = empty_set;

};