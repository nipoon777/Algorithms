#include<bits/stdc++.h>

using namespace std;

//template for generic type

template<typename K, typename V>

class HashNode
{
    public:
    K key;
    V value;
    
    HashNode(K key, V value)
    {
        this->key = key;
        this->value = value;
        
    }
};

template<typename K, typename V>

class HashMap
{
    HashNode<K,V> **arr;
    
    int capacity;
    int size;
    
    HashNode<K,V> *dummy;
    
    public:
    HashMap()
    {
        capacity = 20;
        size = 0;
        
        arr = new HashNode<K,V>*[capacity];
        
        
        for(int i = 0 ; i < capacity ; i++)
        {
            arr[i] = NULL;
        }
        
        dummy = new HashNode<K,V>(-1, -1);
        
    }
    
    int hashCode(K key)
    {
        return key % capacity;
    }
    
    
    void insertNode(K key, V value)
    {
        HashNode<K,V> *temp = new HashNode<K,V>(key,value);
        
        int hashIndex = hashCode(key);
        
        while(arr[hashIndex] != NULL && arr[hashIndex]->key != -1
        && arr[hashIndex]->key != key)
        {
            hashIndex++;
            hashIndex %= capacity;
        }
        
        if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }
    
     V deleteNode(int key) 
    { 
        // Apply hash function to find index for given key 
        int hashIndex = hashCode(key); 
          
        //finding the node with given key 
        while(arr[hashIndex] != NULL) 
        { 
            //if node found 
            if(arr[hashIndex]->key == key) 
            { 
                HashNode<K,V> *temp = arr[hashIndex]; 
                  
                //Insert dummy node here for further use 
                arr[hashIndex] = dummy; 
                  
                // Reduce size 
                size--; 
                return temp->value; 
            } 
            hashIndex++; 
            hashIndex %= capacity; 
  
        } 
          
        //If not found return null 
        return NULL; 
    } 
    
    V get(int key)
    {
        int hashIndex = hashCode(key);
        int counter = 0;
        
        while(arr[hashIndex] != NULL)
        {
            int counter = 0;
            
            if(counter++ >capacity)
            {
                return NULL;
            }
            
            if(arr[hashIndex]->key == key)
            {
                return arr[hashIndex]->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }
    
    int sizeOfMap()
    {
        return size;
    }
    
    bool isEmpty()
    {
        return size == 0;
    }
    
    void display()
    {
        for(int i = 0 ; i < capacity ; i++)
        {
            if(arr[i] != NULL || arr[i]->key != -1)
            {
                cout<<"key="<< arr[i]->key;
                cout<<"value = " << arr[i]->value <<endl;
            }
        }
    }
};

int main() {
	HashMap<int, int> *h = new HashMap<int, int>;
	
	h->insertNode(1,2);
	h->insertNode(2,9);
	h->insertNode(2,19);
	
	h->display();
	
	cout<< h->sizeOfMap() << endl;
	cout<< h->deleteNode(2)<<endl;
	cout<< h->sizeOfMap() << endl;
	cout<< h->isEmpty()<<endl;
	cout<< h->get(5)<<endl;
	
	return 0;
}