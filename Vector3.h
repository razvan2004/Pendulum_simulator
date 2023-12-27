/**
this header contains mainly mathematical functions
Vector3 as a class has 3 coordinates
mathematically, an object Vector3 with variables x,y,z is the vector from the origin of the system to the x,y,z point in space

*/
std::ofstream o("output.txt");
class Vector3
{
public:
    float x;
    float y;
    float z;
    void assignValue(float c1,float c2, float c3);
};
void Vector3::assignValue(float c1, float c2, float c3)
{
    x=c1;
    y=c2;
    z=c3;
}

void assignVector(Vector3 &target, Vector3 val)
{
    target.x=val.x;
    target.y=val.y;
    target.z=val.z;
}
// add v2 to v1
void addVectors(Vector3 &v1,Vector3 v2)
{
    v1.x+=v2.x;
    v1.y+=v2.y;
    v1.z+=v2.z;
}
// the functions returns the scalar product between 2 vectors
float scalarProduct(Vector3 v1, Vector3 v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}
// the function returns the vectorial product
Vector3 vectorialProduct( Vector3 v1, Vector3 v2)
{
    Vector3 product;
    product.x=v1.y*v2.z-v2.y*v1.z;
    product.y=v1.z*v2.x-v1.x*v2.z;
    product.z=v1.x*v2.y-v1.y*v2.x;
    return product;
}
//the function returns the modulus of a vector
float lengthModulus(Vector3 v)
{
    return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
//displays the vector to the console
void displayVector(Vector3 v)
{
    std::cout<<v.x<<" "<<v.y<<" "<<v.z<<" \n";
}
void saveVector(Vector3 v,std::ofstream &out)
{
    out<<std::fixed<<std::setprecision(6);
    out<<v.x<<" "<<v.y<<" "<<v.z<<"\n";
}
void saveWholeVector(Vector3 v,std::ofstream &out)
{
    out<<std::fixed<<std::setprecision(0);
    o<<floor(v.x)<<" "<<floor(v.y)<<" "<<floor(v.z)<<"\n";
}
//rescales the components of a vector by a linear ammount
Vector3 rescale(Vector3 v, float scale)
{
    Vector3 aux;
    assignVector(aux,v);
    aux.x*=scale;
    aux.y*=scale;
    aux.z*=scale;
    return aux;
}
