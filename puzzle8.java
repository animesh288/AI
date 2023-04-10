public class puzzle8{
    public static void main(String[] args) {
        
    }
}
class State{
    State par;
    int mat[][]=new int[3][3];
    int x,y;
    int cost;
    int lev;
    State(int mat[][],int x,int y,State par,int lev){
        this.mat=mat;
        this.x=x;
        this.y=y;
        this.par=par;
        this.lev=lev;
        this.cost=Integer.MAX_VALUE;
    }
}