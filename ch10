#include "../std_lib_facilities.h"

struct Point{

    double x, y;
};

istream& operator >>(istream& is, Point& p)
{
    char ch1;
    if (is >> ch1 && ch1 != '(')
    {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2, ch3;
    double x,y;

    is >> x >> ch2 >> y >> ch3;
    if (!is || ch3 != ')' || ch2 != ',')
    {
        if(is.eof()) return is;
        error("Invalid point");
    }

    p.x = x;
    p.y = y;
    return is;
}

ostream& operator <<(ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ")\n";
}

void input_from_file(vector<Point>& points, string& filename)
{
    ifstream ist { filename };
    ist.exceptions(ist.exceptions()|ios_base::badbit);

    if(!ist) error("Can't open file ", filename);
    for (Point p; ist >> p; )
        points.push_back(p);
}


int main () 
try {
    cout << "Please enter 7 point(s) in the form (x,y):\n";
    vector<Point> originalPoints;

    // Taking input
    while(originalPoints.size() < 7)
    {
        Point p;
        cin >> p;
        originalPoints.push_back(p);
    }

    // Printing
    cout << "Original Points print: \n";
    for (Point p : originalPoints)
        cout << p;

    // Output to file
    string filename = "mydata.txt";
    ofstream ost { filename };
    if(!ost) error("Could not open file ", filename);

    for(Point p : originalPoints)
        ost << p;
    ost.close();

    vector<Point> processed_points;
    input_from_file(processed_points, filename);

    cout << "Processed Points print: \n";
    for (Point p : processed_points)
        cout << p;

    // Error handling 
    if (originalPoints.size() != processed_points.size())
        error ("Something is wrong, possibly the file was altered\n");

    return 0;
}
catch (exception& e){
    cerr << "Error: " << e.what() << '\n';
    return 1;
}
catch (...){
    cerr << "Something went wrong\n";
    return 2;
}
