public class Main extends A{
    public static void main(String[] args) {
        new Main().hey2();
    }
    void hey2(){
        hey();
        ((A)this).hey();
        ((B)this).hey();
        ((C)this).hey();
    }
    void hey(){
        System.out.println(1);
    }
}
class A extends B{
    void hey(){
        System.out.println(1);
    }
}
class B extends C{
    void hey(){
        System.out.println(2);
    }
}
class C{
    void hey(){
        System.out.println(3);
    }
}

