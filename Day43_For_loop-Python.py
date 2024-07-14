#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends



def multiplicationTable(N):
    for i in range(1, 11, 1): 
        # i in range(x,y,z):
        # i goes from x to y-1 and increments z steps in each iteration.
        print(i*N, end=" ") # Separating by spaces using end =" "
        

#{ 
 # Driver Code Starts.


def main():
    testcases=int(input()) #testcases
    while(testcases>0):
        N = int(input())
        multiplicationTable(N)
        print()
        testcases-=1
        


if __name__=='__main__':
    main()
# } Driver Code Ends