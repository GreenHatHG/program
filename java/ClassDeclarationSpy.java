import static java.lang.System.out;//导入后，在代码中可以直接使用out
import java.lang.annotation.Annotation;
import java.lang.reflect.Modifier;
import java.lang.reflect.Type;
import java.lang.reflect.TypeVariable;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class ClassDeclarationSpy {
	public static void main(String[] args) {
		try {
			Scanner in=new Scanner(System.in);
			out.println("请输入一个完整的类名：");
			//可以测试输入java.util.ArrayList或java.lang.Override或[I等
			String className = in.nextLine();
			in.close();
		    Class<?> c = Class.forName(className);
		    
		    out.format("类名:%n  %s%n%n", c.getCanonicalName());//输出通俗名称
		    out.format("修饰符:%n  %s%n%n",
			       Modifier.toString(c.getModifiers()));//获取修饰符并转换成字符串

		    out.format("泛型参数:%n");
		    TypeVariable<?>[] tv = c.getTypeParameters();//获取泛型参数
		    if (tv.length != 0) {
			out.format("  ");
			for (TypeVariable<?> t : tv)
			    out.format("%s ", t.getName());
			out.format("%n%n");
		    } else {
			out.format("  -- 没有泛型参数 --%n%n");
		    }

		    out.format("实现的接口:%n");
		    Type[] intfs = c.getGenericInterfaces();//获取实现的接口
		    if (intfs.length != 0) {
			for (Type intf : intfs)
			    out.format("  %s%n", intf.toString());
			out.format("%n");
		    } else {
			out.format("  -- 没有实现的接口 --%n%n");
		    }

		    out.format("继承路径:%n");
		    List<Class> l = new ArrayList<Class>();
		    printAncestor(c, l);//调用方法获取继承结构
		    if (l.size() != 0) {
			for (Class<?> cl : l)
			    out.format("  %s%n", cl.getCanonicalName());
			out.format("%n");
		    } else {
			out.format("  -- 没有父类 --%n%n");
		    }

		    out.format("注解:%n");
		    Annotation[] ann = c.getAnnotations();//获取使用的注解
		    if (ann.length != 0) {
			for (Annotation a : ann)
			    out.format("  %s%n", a.toString());
			out.format("%n");
		    } else {
			out.format("  --没有注解 --%n%n");
		    }
		} catch (ClassNotFoundException x) {
		    x.printStackTrace();
		}
	    }
	    private static void printAncestor(Class<?> c, List<Class> l) {
		Class<?> ancestor = c.getSuperclass();//获取继承的父类
	 	if (ancestor != null) {
		    l.add(ancestor);//把获得的父类存在列表对象中
		  //通过递归的调用获取父类的父类，直到Object类没有父类为止
		    printAncestor(ancestor, l);
	 	}
	    }
}
