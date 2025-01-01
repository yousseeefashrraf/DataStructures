
import Foundation
public class cNode {
    public var value: Int
    public var next: cNode!
    
    public init() {
        self.value = 0
        self.next = nil
    }
    
    public init(value: Int, next: cNode!) {
        self.value = value
        self.next = next
    }
}

public class linkedList{
    public var head: cNode!
    public var tail: cNode!
    
    
   public init(head: cNode! = nil, tail: cNode! = nil) {
        self.head = head
        self.tail = tail

    }
    
    public func addLast(value: Int){
        let newNode = cNode(value: value, next: nil)
    if head == nil {
        head = newNode
        tail = newNode
        print("Hello")
    } else {
        tail.next = newNode
        tail = newNode
    }
}
    public func addFirst (value: Int){
        let newNode = cNode(value: value, next: head)
        head = newNode
    }
    public func listOut(){
        var nTrav = head
        print("[",terminator: "")
        while nTrav != nil{

            print("\(nTrav?.value ?? 0)\((nTrav?.next != nil) ? (", ") : "")", terminator: "")

            nTrav = nTrav?.next
        }
        print("]")
    }
    
}

