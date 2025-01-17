/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  if (length_ == 0) {
    return;
  }
  ListNode* curr = tail_->prev;
  while (curr != NULL) {
    delete curr->next;
    curr = curr->prev;
    length_ --;
  }
  delete head_;
  head_=NULL;
  tail_=NULL;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if (length_ == 0) {
    length_ = 1;
    head_= tail_ = newNode;
    return;
  }
  head_ -> prev = newNode;
  newNode -> next = head_;
  head_=newNode;
  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if (length_ == 0) {
    length_ = 1;
    head_= tail_ = newNode;
    return;
  }
  newNode -> prev = tail_;
  tail_ -> next = newNode;
  tail_ = newNode;
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode* curr = start;
  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }
  if (curr != NULL) {
    if (curr->prev != NULL) {
      curr->prev->next = NULL;
    }
    curr->prev = NULL;
  }
  return curr;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  if (length_ < 3) {
    return;
  }
  int count = length_;
  ListNode* curr = head_;
  while (count - 3 >= 0) { // while it is still a multiple of 3
    ListNode* second = curr->next;
    ListNode* third = second->next;
    if (curr == head_) { // if head_ is being modified
      head_ = head_->next; // set head_ = whatever is next
    }
    if (curr->prev == NULL) {
      second->prev=NULL;
    } else {
      second->prev = curr->prev;
      curr->prev->next = curr->next;
    }
    curr->prev = third;
    curr->next = third->next;
    if (third->next != NULL) {
      third->next->prev = curr;
    }
    third->next = curr;
    if (third==tail_) {
      tail_ = curr;
    }
    count-=3;
    curr=curr->next;
  }
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  // /// @todo Graded in MP3.2
 if (startPoint == endPoint) {
    return;
  }

  ListNode* curr=startPoint;
  ListNode* ending=endPoint->next;
  ListNode* beginning=startPoint->prev;
  
  while (curr != endPoint) {
    ListNode* after = curr->prev;
    curr->prev = curr->next;
    curr->next = after;
    curr = curr->prev;
  }

  curr->next = curr->prev;
  curr->prev = beginning;
  startPoint->next = ending;

  // modify the beginning and end of the lists to link them
  if (beginning != NULL) {
    beginning->next = endPoint;
  } else {
    head_ = endPoint;
  }

  if (ending != NULL) {
    ending->prev = startPoint;
  } else {
    tail_ = startPoint;
  }  
  ListNode* s=startPoint;
  startPoint = endPoint;
  endPoint = s;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  if (head_ == NULL) {
    return;
  }
  ListNode* start = head_;
  ListNode* end = head_;
  while (start != NULL) {
    end = start;
    for (int i = 0; i < n-1; i++) {
      if (end->next != NULL) {
        end = end->next;
      }
    }
    reverse (start, end);
    start = end->next;
  }
  return;
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode *output;
	if (second->data < first->data) {
    output = second;
		second = second->next;
	} else {
		output = first;
		first = first->next;
	}

	ListNode *curr = output;
	while ((first != NULL) && (second != NULL)) {
		if (second->data < first->data) {
			curr->next = second;
			second->prev = curr;
			second = second->next;
		} else {
			curr->next = first;
			first->prev = curr;
			first = first->next;
		}
		curr = curr->next;
	}

	while ((first != NULL) && (second == NULL)) {
		curr->next = first;
		first->prev = curr;
    first=first->next;
    curr = curr->next;
	}
  
	while ((first == NULL) && (second != NULL)) {
		curr->next = second;
		second->prev = curr;
    second=second->next;
    curr=curr->next;
	}

  first=output;
	return output;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (start == NULL || chainLength <= 1) {
    return start;
  }

  ListNode *middle = split(start, chainLength / 2);
  int new_length = (chainLength % 2) + (chainLength / 2); // depending on odd or even lengths

  return merge(mergesort(start, chainLength / 2), mergesort(middle, new_length));
}
