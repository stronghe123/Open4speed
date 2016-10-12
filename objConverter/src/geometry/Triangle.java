package geometry;

// 3d points connected into triangle
public class Triangle
{

  public Vertex a, b, c;
  public int    cell;

  public Triangle(Vertex a, Vertex b, Vertex c)
  {
    this.a = a;
    this.b = b;
    this.c = c;
  }

  // compressed values of triangle
  public byte[] value()
  {
    String output = a.value() + b.value() + c.value() + "\n";
    return output.getBytes();
  }
}