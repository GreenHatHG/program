import java.lang.reflect.*;
import java.util.*;

public class parseAnnotationTest{
    public static void main(String[] args)throws Exception{
        Scanner in = new Scanner(System.in);
        System.out.println("请输入一个字符串");
        String input = in.nextLine();

        Class c = Class.forName("useAnnotationTest");
        Method[] methods = c.getDeclaredMethods();
        Boolean flag = false;
        for(Method m: methods){
            AnnotationTest anno = m.getAnnotation(AnnotationTest.class);
            if(anno.s().equals(input)){
                System.out.println("匹配成功");
                System.out.println("调用该函数:");
                m.invoke(c.newInstance());
                flag = true;
                break;
            }
        }
        if(!flag)
            System.out.println("匹配不成功");
    }
}
