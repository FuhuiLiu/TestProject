#include "com_example_jnidemo_JNIDemo.h"
#include <android/log.h>

JNIEXPORT jint JNICALL MyAdd
  (JNIEnv *env, jclass jobj, jint n1, jint n2)
{
	return n1 - n2;
}

JNINativeMethod methods[] = {
		"MyAdd", \
		"(II)I", \
		(void*)MyAdd};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","JNI_OnLoad");

	void *env;
	jint nRet = vm->GetEnv(&env, JNI_VERSION_1_4);
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","GetEnv");

	jclass clsJNIDemo = ((JNIEnv *)env)->FindClass("com/example/jnidemo/JNIDemo");
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","JNIDemo");

	jint nResult = ((JNIEnv *)env)->RegisterNatives(clsJNIDemo, methods, 1);
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","RegisterNatives");

	if (nResult < 0)
		return 0;

	return JNI_VERSION_1_4;
}
/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    NdkCallJava
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jnidemo_JNIDemo_NdkCallJava
  (JNIEnv *env, jclass jobj)
{
	//1.经由虚拟机查想要的类
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","NdkCallJava");
	jclass clsMainActivity = env->FindClass("com/example/jnidemo/MainActivity");
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","FindClass");

	//2.查找类的方法，初始化的名为"<init>"，sig的返回值跟参数都必须是大写的
	jmethodID idMainActivity = env->GetMethodID(clsMainActivity, "<init>", "()V");
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","GetMethodID");

	//3.调用虚拟机生成这个类对象
	jobject obj = env->NewObject(clsMainActivity, idMainActivity);
	if (obj == 0)
	{
		__android_log_print(ANDROID_LOG_INFO,"JNIDemo","NewObject fail");
		return ;
	}
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","NewObject success");

	//4.对象产生后再查询要调用的方法
	jmethodID idMainAdd = env->GetMethodID(clsMainActivity, "MainAdd", "(II)I");
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","GetMethodID MainAdd");

	//5.调用目标方法
	jint nResult = env->CallIntMethod(obj, idMainAdd, 1, 2);
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","Method 1 + 2 = %d", nResult);
}

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MyAdd
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnidemo_JNIDemo_MyAdd
  (JNIEnv *env, jobject obj, jint n1, jint n2)
{
//	int n = n1 + n2;
//	__android_log_print(ANDROID_LOG_INFO,"" + n,"FindClass");
	return n1 + n2;
}

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MySub
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnidemo_JNIDemo_MySub
  (JNIEnv *evn, jobject obj, jint n1, jint n2)
{
	return n1 - n2;
}

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MyGetString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnidemo_JNIDemo_MyGetString
  (JNIEnv *env, jobject obj)
{
	return env->NewStringUTF("Hello world!\r\n");
}

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    StaticMothod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jnidemo_JNIDemo_StaticMothod
  (JNIEnv *, jclass)
{
	__android_log_print(ANDROID_LOG_INFO,"JNIDemo","StaticMothod");
}
