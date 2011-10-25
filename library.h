/*
 * qsort.h
 *
 *  Created on: Oct 22, 2011
 *      Author: Rich Tufano
 */

#ifndef QSORT_H_
#define QSORT_H_

/**
 * ==============================================================================
 * function qsort
 * sorts the array of data v, from v[left] to v[right] in increasing order.
 * This function does not return anything, but manipulates the actual data itself.
 *
 * *v - the data to sort
 * left - the index of the beginning of the data to sort from
 * right - the index of the end of the data to sort to
 * (*comp)(void *, void *) - the function to use to compare the two data
 * ==============================================================================
 */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *)){
	// i -> iterator while looping through the data, to use while comparing
	// last -> stores the index of the last index swapped
	int i, last;
	// function declaration for the swap function
	void swap(void *v[], int, int);

	/*
	 * if left is >= right (remember these are indices), then there is only one
	 * element in this set, and we've reached the terminal case for this recursive function
	 */
	if(left>=right)
		return;

	/* swap the first element in this subset, and the element in the middle of this subset	 */
	swap(v, left, (left + right)/2);

	/* set the last element swapped to the front of this subset */
	last = left;

	/*
	 * iterate through this loop, starting at the 2nd element in the subset,
	 * and ending at the element at the end of this subset
	 * i will be used to designate the which element in the subset is going
	 * to be compared.
	 */
	for (i = left+1; i <= right; i++)
		/*
		 * call the compare function that was supplied to the qsort function.
		 * If comp returns anything less then zero, then the element at index
		 * i in the subset is less then the index at the beginning at this set,
		 * and should therefor be swapped with the element at the beginning.
		 *
		 * LAST will only be incremented if an element's been swapped!!!
		 *==============================================================================
		 * IF NOT, don't do anything.
		 */
		if( (*comp)(v[i], v[left]) < 0 )
			swap(v, ++last, i);

	/* swap the last element swapped, and the first element compared in this set. */
	swap(v, left, last);
	/* qsort the first half of the list, going from the start of the subset, to the number of the last element swapped*/
	qsort(v, left, last-1, comp);
	/* qsort the second half of the list, going from the element after the last element, to the end of the subset */
	qsort(v, last+1, right, comp);
}

/**
 * ==============================================================================
 * function swap -
 * swap the elements at position i, and position j from the set v[]
 *
 * does not return anything, but rather swaps the actual elements in the array.
 * ==============================================================================
 */
void swap(void *v[], int i, int j){
	/* create a temporary variable to hold the element at index i, of type void* */
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int stoi

#endif /* QSORT_H_ */
