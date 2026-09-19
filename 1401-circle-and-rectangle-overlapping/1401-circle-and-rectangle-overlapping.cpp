class Solution {
public:
    bool checkcircleEqn(int radius , int xc , int yc , int x1 , int y1){
        int r =  radius* radius ; 
        int X = (x1 - xc)*   (x1 - xc) ; 
        int Y = (y1 - yc) * (y1 - yc) ; 
        if(X+Y <= r) return true ; 
        return false ; 
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2) {
            return true;
        }
        for(int y = y1 ; y <= y2 ; y++){
            if( checkcircleEqn(radius , xCenter , yCenter , x1 , y)){
                return true ; 
            }else if(checkcircleEqn(radius , xCenter , yCenter , x2 , y)) return true ;

        }

        for(int x = x1 ; x <= x2 ; x++){
            if(checkcircleEqn(radius , xCenter , yCenter , x , y1)){
                return true ; 
            }else if(checkcircleEqn(radius , xCenter , yCenter , x , y2)){
                return true ;
            }
        }

        return false ;
    }
};