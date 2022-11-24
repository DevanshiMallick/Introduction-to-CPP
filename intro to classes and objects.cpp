#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
    public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list <string> PublishedVideoTitles;

};

int main(){
    YoutubeChannel ytChannel;
    ytChannel.Name="CodeBeauty";
    ytChannel.OwnerName="Saldina";
    ytChannel.SubscribersCount=1800;
    ytChannel.PublishedVideoTitles={"C++ Beginners Video 1","HTML & CSS", "OOPs"};

    cout<<"Name: "<<ytChannel.Name<<endl;
    cout<<"OwnerName: "<<ytChannel.OwnerName<<endl;
    cout<<"SubscriberCount: "<<ytChannel.SubscribersCount<<endl;
    cout<<"Videos: "<<endl;
    for (string videoTitle: ytChannel.PublishedVideoTitles){
        cout<<videoTitle<<endl;
    }}
