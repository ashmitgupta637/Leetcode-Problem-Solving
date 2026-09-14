class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1_rec1 = rec1[0]  ; 

        int y1_rec1 = rec1[1]  ; 

        int x2_rec1 = rec1[2]  ; 
        int y2_rec1 = rec1[3]  ;

        int x1_rec2 = rec2[0]  ; 

        int y1_rec2 = rec2[1]  ; 

        int x2_rec2 = rec2[2]  ; 
        int y2_rec2 = rec2[3]  ;

        if(x1_rec1 >= x2_rec2 || y1_rec1 >= y2_rec2 || y2_rec1 <= y1_rec2 || x2_rec1 <= x1_rec2 ){
            return false ; 
        }
        return true ; 
    }
};