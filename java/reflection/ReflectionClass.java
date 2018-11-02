import java.io.*;
import java.lang.reflect.*;

public class ReflectionClass {
	public static void main(String[] args) {
		try {
		    InputStreamReader in = new InputStreamReader(new FileInputStream("./Sourcefile.txt"));
            BufferedReader bf = new BufferedReader(in);
            String s = bf.readLine();

			Class cla = Class.forName(s);		
			System.out.println("该类有关修饰符和类型参数的信息:");
			System.out.println(cla.toGenericString());
			
			System.out.println("该类的父类:");
			System.out.println(cla.getSuperclass());
			Type[] genericInterfaces = cla.getGenericInterfaces();
			System.out.println("该类实现的接口:");
			if(genericInterfaces.length != 0){
				for(Type interfaces : genericInterfaces)
					System.out.println(interfaces.toString());
			}else {
				System.out.println("该类没有实现的接口");
			}
				
			Field[] fields = cla.getDeclaredFields();
			System.out.println("该类中所有定义的属性:");
			if(fields.length != 0) {
				for(Field f : fields) {
					System.out.println(f.toGenericString());
				}
			}else {
				System.out.println("该类没有定义的属性");
			}
			
			Constructor[] constructors = cla.getDeclaredConstructors();
			System.out.println("该类的构造办法:");
				for(Constructor cons : constructors) {
					System.out.println(cons.toGenericString());
				}
				
			Method[] methods = cla.getDeclaredMethods();
			System.out.println("该类的公有成员方法:");
			if(fields.length != 0) {
				for(Method me : methods) {
					System.out.println(me.toGenericString());
				}
			}else {
				System.out.println("该类没有公有成员方法");
			}
			
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch(FileNotFoundException e){
            e.printStackTrace();
        } catch(IOException e){
            e.printStackTrace();
        }
		
	}
}
