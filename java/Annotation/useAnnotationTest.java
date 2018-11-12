public class useAnnotationTest{
    private String s1;

    @AnnotationTest(s = "test1")
    public void f1(){
        System.out.println("AnnotationTest(s = \"test1\")");
    }

    @AnnotationTest(s = "test2")
    public void f2(){
        System.out.println("AnnotationTest(s = \"test2\")");
    }

    @AnnotationTest(s = "test3")
    public void f3(){
        System.out.println("AnnotationTest(s = \"test3\")");
    }
}
