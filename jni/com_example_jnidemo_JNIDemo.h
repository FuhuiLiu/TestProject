/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_jnidemo_JNIDemo */

#ifndef _Included_com_example_jnidemo_JNIDemo
#define _Included_com_example_jnidemo_JNIDemo
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    NdkCallJava
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jnidemo_JNIDemo_NdkCallJava
  (JNIEnv *, jclass);

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MyGetString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnidemo_JNIDemo_MyGetString
  (JNIEnv *, jobject);

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    StaticMothod
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_jnidemo_JNIDemo_StaticMothod
  (JNIEnv *, jclass);

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MySub
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnidemo_JNIDemo_MySub
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     com_example_jnidemo_JNIDemo
 * Method:    MyAdd
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnidemo_JNIDemo_MyAdd
  (JNIEnv *, jobject, jint, jint);

#ifdef __cplusplus
}
#endif
#endif