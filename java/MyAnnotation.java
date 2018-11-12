import static java.lang.annotation.RetentionPolicy.RUNTIME;

//import java.lang.annotation.Retention;

@Retention(RUNTIME)//运行时注解
public @interface MyAnnotation {
	String author() default "gcu";
	String date() default "2018";
	

}
