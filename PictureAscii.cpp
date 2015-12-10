#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;


//Character set for the ASCII Art in decreasing order of brightness, can be tuned for better results
string coding = " .:-~=+?I7$0K8ZNM#";
int charwid = 100;
int main(int argc, char** argv)
{
	if (argc>=3)
	{
		//Reading grayscale image
		Mat input = imread(argv[1],IMREAD_GRAYSCALE);

		
		freopen(argv[2],"w",stdout);
	    
	    imshow("input",input);
	  
	    Mat scaled;

	    if (argc>=4)
	    {
	    	charwid = atoi(argv[3]);
	    }
	  	
	  	//Assuming row size to be 100 characters and calculating the resize ratio
	    double factor = (charwid/(double)input.cols);
	  
	  	//Resizing the image, CV_INTER_AREA is used as it is generally shrinkage
	    resize(input, scaled, Size(),factor,factor*0.50,CV_INTER_AREA);

	    imshow("resized",scaled);
	  
	    int codesize = coding.size();
	   
	    double codeindex = codesize/255.0;  //The factor to calculate the index of the coding

	    for(int i=0;i<scaled.rows;i++)
	    {
	    	for (int j=0;j<scaled.cols;j++)
	    	{
	    		Scalar intensity = scaled.at<uchar>(i, j);  //To get the pixle value
	    		double intense = 255 - intensity[0];  

	    		//Calculating the character for the pixle
	    		int ind = min (codesize-1,int(intense*codeindex));
	    		ind = max (0, ind);
	    		
	    		//printing the character
	    		cout<<coding[ind];
	    		
	    	}
	    	cout<<endl;
	    }
	   

	    waitKey(0);
	}
	else
	{
		cout<<"Please enter path of Image\n";
	}


    return 0;
}