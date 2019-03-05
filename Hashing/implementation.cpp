#include<bits/stdc++.h>
using namespace std;

template<typename v>
class MapNode
{public:
  string key;
  V value;
  MapNode * next;
  MapNode(string key, V value)
  {
    this->key = key;
    this-value = value;
    next = NULL;
  }

  ~MapNode()
  {
    delete next;
  }
}

class ourmap
{
  MapNode<V>** buckets;
  int count;
  int numBuckets;

public:
  ourmap()
  {
    count = 0;
    numBuckets = 5;
    buckets = new MapNode<V> * [numBuckets];

    for(int i = 0;i<numBuckets;i++)
    {
      buckets[i] = NULL;
    }}

    ~ourmap()
    {
      for(int i = 0; i < numBuckets; i++)
      {
        delete [] buckets[i];
      }
      delete [] buckets;
    }

    int size()
    return count;
private:
  int getbucketindex(string key)
  {
    int hashcode;
    int currentcoeff = 1;
    for(int i = key.length()-1;i>=0;i--)
    {
      hashcode += key[i] * currentcoeff;
      hashcode%=numBuckets;
      currentcoeff*=37;
      currentcoeff%=numbuckets;
    }
    return hashcode%numBuckets;
  }

  void rehash(){
    MapNode<V>** temp = bucket;
       buckets = new MapNode<V>*[2*numBuckets];
       for(int i = 0; i < 2*numBuckets; i++)
       {
         buckets[i] = NULL;
       }
      int oldbucketscount = numBuckets;
      numbuckets *= 2;
      count = 0;

      for(int i = 0; i < oldbucketscount ;i++)
      {
        MapNode<V>*head = temp[i];
        while(head!=NULL)
        {
          string key = head->key;
          V value = head->value;
          insert(key,value);
          head = head->next;
        }
  }

for(int i=0;i<oldbucketscount;i++)
{
  MapNode<V>*head = temp[i];
  delete head;
}

delete [] temp;
}



public:
    V getvalue(string key)
    {
      int bucketindex = getbucketindex(key);

      while(head!=NULL)
      {
        if(head->key == key)
        {
          return head->value;
        }
        head = head->next;
      }
      return 0;}


    void insert(string key, V value)
    {
      int bucketindex = getbucketindex(key);
      MapNode<V>*head = buckets[bucketindex];

      while(head!=NULL)
      {
        if(head->key == key)
         {head->value = value;
           return;}
        head = head->next;
      }

      head = buckets[bucketindex];
      MapNode<V>* node = new MapNode<V>(key,value);
      node->next = head;
      buckets[bucketindex] = node;
      count++;
      double loadfactor = (1.0 * count)/numBuckets;
      if(loadfactor>0.7)
      {
        rehash();
      }

    }

    V remove (string key)
    {
      int bucketindex = getbucketindex(key);
      MapNode<V> * head = buckets[bucketindex];
      MapNode<V> * prev = NULL;
      while(head!=NULL)
      {
        if(head->key==key)
        {
          if(prev==NULL)
          {
            buckets[bucketindex] = head->next;
          }
          else
          prev->next = head->next;

          V value = head->value;
          head->next = NULL;
          delete head;
          count--;
          return value;

        }
        prev = head;
        head = head->next;
      }
      return 0;

    }
}
