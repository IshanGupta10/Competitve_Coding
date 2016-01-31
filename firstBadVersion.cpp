// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int start = 1, end = n;
        int middle;
        if(isBadVersion(start) && isBadVersion(end))
            return start;
        while(start <= end)
        {
            middle = (start + end)/2;
            // if(isBadVersion(mid) && !isBadVersion(mid-1) && isBadVersion(mid+1))
            //     return mid;
            // if(!isBadVersion(mid) && !isBadVersion(low) && isBadVersion(high))
            //     low = mid + 1;
            // if(isBadVersion(mid) && !isBadVersion(low) && isBadVersion(high))
            //     high = mid - 1;
            middle = ((end-start)>> 1) + start;
            if(isBadVersion(middle)) 
                end = middle - 1;
            else 
                start = middle + 1;
        }
        return end + 1;
    }
};