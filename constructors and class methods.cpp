#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
    public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list <string> PublishedVideoTitles;
    
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
        cout<<videoTitle<<endl;
    }
    }
};

int main(){
    YoutubeChannel ytChannel("CodeBeauty","Saldina");
    ytChannel.PublishedVideoTitles.push_back("ABC");
    ytChannel.PublishedVideoTitles.push_back("DEF");
    ytChannel.PublishedVideoTitles.push_back("GHI");
    
    YoutubeChannel ytChannel2("AmieSings","Amie");
    
    ytChannel.GetInfo();
    ytChannel2.GetInfo();

}