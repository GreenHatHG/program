import java.io.*;
import java.lang.reflect.*;
public class ReflectionMethon {
	public static void main(String[] args){
        Class<TestClass> cla = TestClass.class;
		try {
		    InputStreamReader in = new InputStreamReader(new FileInputStream("./Sourcefile.txt"));
            BufferedReader bf = new BufferedReader(in);
            String s = "", tmp;
            int n = 0;
            while ((tmp = bf.readLine()) != null){
                n++;
                if(n == 2)
                    s = new String(tmp);
            } 
			Object obj = cla.newInstance();
			
			Method method = cla.getDeclaredMethod(s);			
			method.invoke(obj);
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch(NoSuchMethodException e) {
			e.printStackTrace();
		} catch(InvocationTargetException e) {
			e.printStackTrace();
		} catch(IOException e){
            e.printStackTrace();
        }
	}
}
