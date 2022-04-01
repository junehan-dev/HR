#include <stdio.h>
int	find_min(int *nums, int n)
{
	int	l = 0;
	int	m = n / 2;
	int	h = n - 1;

	if (nums[0] < nums[n-1])
		return (0);

	while (l <= h) {
		if (nums[m] < nums[l]) {
			h = m;
			l += 1;
			printf("%d mid < start %d\n", nums[m], nums[l]);
		}
		else if (nums[m] > nums[h]) {
			l = m + 1;
			printf("%d mid > end %d\n", nums[m], nums[h]);
		} else {
			printf("found %d lowest\n", nums[m]);
			return (m);
		}
		m = (h + l) / 2;
	}
	return (m);
}

int	search(int *nums, int n, int t)
{
	int min;

	if (t > n-1)
		return (-1);

	min = find_min(nums, n);
	printf("min: %d\n", min);
	printf("min at %d: %d\n", t,min+t);
	return (((min + t) > (n - 1)) ? nums[min + t - n] : nums[min + t]);
}
int main(void)
{
	int test[5] = {3,4,5,0,1};
	int ret = search(test, 5, 1);
	printf("%d is %d lowest",ret, 1); 
	return (0);
}

