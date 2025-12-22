# Data Structures Quiz (MCQs)

## Instructions
- Choose the correct answer for each question.
- Questions are ordered from easy to hard.
- Do NOT check answers until you finish the quiz.

---

## Questions

**Q1.** What is `std::vector` in C++?  
A) Static array  
B) Dynamic array  
C) Linked list  
D) Stack  

---

**Q2.** Where is `std::vector` stored in memory?  
A) Stack only  
B) Heap only  
C) Both stack and heap  
D) Registers  

---

**Q3.** Which header is required to use `std::vector`?  
A) <array>  
B) <list>  
C) <vector>  
D) <deque>  

---

**Q4.** Accessing an element by index in a vector takes:  
A) O(n)  
B) O(log n)  
C) O(1)  
D) O(n log n)  

---

**Q5.** What does `push_back()` do?  
A) Removes the last element  
B) Inserts an element at the beginning  
C) Adds an element at the end  
D) Sorts the vector  

---

**Q6.** The amortized time complexity of `push_back()` is:  
A) O(n)  
B) O(log n)  
C) O(1)  
D) O(n²)  

---

**Q7.** Why can `push_back()` sometimes take O(n)?  
A) Due to recursion  
B) Due to resizing and copying  
C) Due to sorting  
D) Due to hashing  

---

**Q8.** What happens when a vector runs out of capacity?  
A) It crashes  
B) It resizes and copies elements  
C) It deletes elements  
D) It switches to linked list  

---

**Q9.** Which function returns the number of elements in a vector?  
A) capacity()  
B) size()  
C) length()  
D) count()  

---

**Q10.** What does `capacity()` return?  
A) Number of elements  
B) Maximum possible size  
C) Allocated storage size  
D) Size in bytes  

---

**Q11.** Which operation is expensive in a vector?  
A) Access by index  
B) Insert at the end  
C) Insert at the beginning  
D) Read last element  

---

**Q12.** Inserting an element at the beginning of a vector costs:  
A) O(1)  
B) O(log n)  
C) O(n)  
D) O(n²)  

---

**Q13.** Which operation removes the last element?  
A) erase()  
B) delete()  
C) pop_back()  
D) clear()  

---

**Q14.** `vector.clear()` does:  
A) Frees capacity  
B) Removes all elements  
C) Deletes the vector  
D) Shrinks memory automatically  

---

**Q15.** After calling `clear()`, the vector size is:  
A) unchanged  
B) zero  
C) undefined  
D) equal to capacity  

---

**Q16.** Which function can reduce unused capacity?  
A) resize()  
B) reserve()  
C) shrink_to_fit()  
D) clear()  

---

**Q17.** Which iterator points to the first element?  
A) begin()  
B) front()  
C) start()  
D) first()  

---

**Q18.** Which iterator points past the last element?  
A) last()  
B) end()  
C) back()  
D) finish()  

---

**Q19.** `std::vector` elements are stored:  
A) Randomly  
B) Contiguously  
C) As nodes  
D) As hash buckets  

---

**Q20.** `std::vector` is best used when:  
A) Frequent insertions in middle are needed  
B) Constant-time access is required  
C) Memory is extremely limited  
D) Data size is fixed forever  

---

## Answers

1. B  
2. B  
3. C  
4. C  
5. C  
6. C  
7. B  
8. B  
9. B  
10. C  
11. C  
12. C  
13. C  
14. B  
15. B  
16. C  
17. A  
18. B  
19. B  
20. B  
