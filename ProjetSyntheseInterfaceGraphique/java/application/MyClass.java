package application;

public class MyClass {
    public native void myPrint(String s, int i);
    public static void main(String[] args){
        new MyClass().myPrint("Hello world", 5);
    }
    static{
        System.loadLibrary("mylibrary");
    }
}
