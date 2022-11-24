#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
private:
//shoudnt be accessible by others, so make it private
    string Name;
    string OwnerName;
    int SubscribersCount;
    list <string> PublishedVideoTitles;
    
public:
    //constructors
    YoutubeChannel (string name, string ownerName){
        Name= name;
        OwnerName= ownerName;
        SubscribersCount= 0;
        }
        
    //class methos- we write info of class
    void GetInfo(){
         cout<<"Name: "<<Name<<endl;
        cout<<"OwnerName: "<<OwnerName<<endl;
        cout<<"SubscriberCount: "<<SubscribersCount<<endl;
        cout<<"Videos: "<<endl;
        for (string videoTitle: PublishedVideoTitles){
            cout<<videoTitle<<endl;}
    }
    
    // what if the user wants to subscrobe or Unsubscribe
    //we make class methods for that
    void Subscribe(){
        SubscribersCount++;
    }
    
    
    //has a bug---subscriber count cannot be in negative--so we introduce a if and else
    void Unsubscribe(){
        if (SubscribersCount>0) SubscribersCount--;
    }
    
    //what if we want to add a video title to the channel
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }
    
    //since Name and Owner Name are private members of the class - we can make a getter and setter methods
};

int main(){
    YoutubeChannel ytChannel("CodeBeauty","Saldina");
    //cannot access that because theu are priivate memeber now of the class
    //ytChannel.PublishedVideoTitles.push_back("ABC");
    //ytChannel.PublishedVideoTitles.push_back("DEF");
    //ytChannel.PublishedVideoTitles.push_back("GHI");
    
    //instead we use the class mwthods
    ytChannel.PublishVideo("ABC");
    ytChannel.PublishVideo("DEF");
    ytChannel.PublishVideo("GHI");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    
    
    YoutubeChannel ytChannel2("AmieSings","Amie");
    
    ytChannel.GetInfo();
    ytChannel2.GetInfo();

}