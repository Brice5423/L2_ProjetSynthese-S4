#include "application_MyClass.h"
#include "util.h"

JNIEXPORT void JNICALL Java_application_MyClass_myPrint(JNIEnv *env, jobject obj, jstring s, jint i){
const char *mystring = (*env)->GetStringUTFChars(env, s, NULL);
printString(mystring);
printInt(i);
}