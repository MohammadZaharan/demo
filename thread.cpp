#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int a=10;
pthread_mutex_t lock;

void*  function1 (void* ar)
{
    //lock
    pthread_mutex_lock(&lock);
    a=a+10;
    cout<<"inside function1 a : "<<a<<endl;
    cout<<"inside function1 a : "<<a<<endl;
    cout<<"inside function1 a : "<<a<<endl;
    cout<<"inside function1 a : "<<a<<endl;
    cout<<"inside function1 a : "<<a<<endl;
    //cout<<a+a<<endl;
    //unlock
   pthread_mutex_unlock(&lock);
}
void*  function2 (void* ar)
{
   pthread_mutex_lock(&lock);

   a=a+10;
   cout<<"inside function2 a : "<<a<<endl;
  pthread_mutex_lock(&lock);

}
void*  function3 (void* ar)
{
  pthread_mutex_lock(&lock);
   a=a+10;
   cout<<"inside function3 a : "<<a<<endl;
   pthread_mutex_lock(&lock);
}
int main()
{
    cout<<"hello this is main"<<endl;
   pthread_mutex_init(&lock, NULL);
    // if(sucess!=0)
    // {
    //   cout<<"error"<<endl;
    // }
    pthread_t t1,t2,t3;
    cout<<"inside main a : "<<a<<endl;
    pthread_create(&t1,NULL,function1,NULL);// API to create 
    pthread_create(&t2,NULL,function2,NULL);
    pthread_create(&t3,NULL,function3,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
   

}