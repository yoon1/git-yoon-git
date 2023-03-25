package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	t := make([]int, m+n)
	copy(t, nums1)

	var mi, ni, ti int
	for ti < m+n && mi < m && ni < n {
		if nums1[mi] < nums2[ni] {
			t[ti] = nums1[mi]
			mi++
		} else {
			t[ti] = nums2[ni]
			ni++
		}

		ti++
	}

	for ni < n {
		t[ti] = nums2[ni]
		ni++
		ti++
	}

	for mi < m {
		t[ti] = nums1[mi]
		mi++
		ti++
	}

	copy(nums1, t)
}
