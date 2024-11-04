1146. Snapshot Array

Intuition
To store the array elements in the least possible space, a list of lists is the ideal approach. To increase the efficiency of the searching algorithm (particularly the get() function), use binary search.
This approach uses a map to increase the efficiency of the searching (indexing) process. You can use a vector<vector<pair<int,int>>> as well for the same purpose.

Approach
Create a list of lists of pairs of integers (done here using map<int,vector<pair<int,int>>>) to store the elements and the corresponding snap_id for each change introduced to the elements.
Initialise a variable, sn, to store the latest snap_id.
For the constructor, push a new pair {0,0} to each list in the parent list.
For the set() function, corresponding to the given index, check if the last entry corresponds to the current snap:
If yes, the value previously stored (i.e. the last element of m[index]) is not important and can be erased. So overwrite the element entry to store the new value.
Else, push a new value, {value,sn} to the list corresponding to index (i.e. m[index]).
For the snap() function, return sn and increment it by 1.
For the get() function:
If the first element m[index] corresponds to the required snap_id then return m[index][0].first
Else, perform a binary search on the list m[index] and find the element corresponding to the required snap_id as either m[index][i].second==snap_id, or m[index][i].second<snap_id && m[index][i+1].second>snap_id.
If the binary search terminates without finding the required element, return m[index][m.size()-1].first i.e. the last element of the list corresponding to index (since this means that the element has not been updated between the last snap and this snap).
Complexity
Time complexity: O(log(length))
Space complexity: O(length.sn)
(Here sn represents the highest snap_id)

class SnapshotArray {
public:
map<int,pair<int,int>> m;
int sn = 0;
    
    SnapshotArray(int length) {
        for(int i=0;i<length;i++){
            m[i].push_back({0,sn});
        }
    }
    
    void set(int index, int val) {
        int size = m[index] - 1;
        if(m[index][size].second==sn){
            m[index][size].first = val;
        }
        else{
            m[index].push_back({val,sn});
        }
    }
    
    int snap() {
        return sn++;
    }
    
    int get(int index, int snap_id) {
        if(m[index].size()==1 || m[index][0].second==snap_id){
            retrun m[index][0].first;
        }
        int l=0, r = m[index].size() - 1;
        while(l<=r){
            int mid =(l+r)/2;
            if(mid == m[index].size()-1){
                return m[index][m[index].size()-1].first;
            }
            if(m[index][mid].second<=snap_id && m[index][mid+1].second>snap_id){
                return m[index][mid].first;
            }
            else if(m[index][mid].second>snap_id){
                r = mid-1;
            }
            else{ l = mid+1;}
        }
        return m[index][m[index].size()-1].first;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */