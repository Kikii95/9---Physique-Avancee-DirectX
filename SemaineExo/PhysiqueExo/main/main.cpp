#include <iostream>
#include <cmath>

using namespace std;

// struct basique pour les vecteurs
struct Vec3
{
    float x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
};

//===========================================
// Exercice 1 : Euler explicite
// m=2kg, F=(4,0,0)N, repos, dt=0.1s
//===========================================
void Exo1_EulerExplicite()
{
    cout << "=== Exo 1 : Euler Explicite ===" << endl;

    float m = 2.0f;
    Vec3 F(4.0f, 0.0f, 0.0f);
    Vec3 v(0, 0, 0);  // repos
    Vec3 x(0, 0, 0);
    float dt = 0.1f;

    // a = F/m
    Vec3 a = F * (1.0f / m);

    // euler explicite: v1 = v0 + a*dt
    Vec3 v1 = v + a * dt;

    cout << "a = " << a.x << " m/s2" << endl;
    cout << "v1 = " << v1.x << " m/s" << endl;
    cout << endl;
}

//===========================================
// Exercice 2 : Euler semi-implicite
// meme objet, calcul v1 et x1
//===========================================
void Exo2_EulerSemiImplicite()
{
    cout << "=== Exo 2 : Euler Semi-Implicite ===" << endl;

    float m = 2.0f;
    Vec3 F(4.0f, 0.0f, 0.0f);
    Vec3 v0(0, 0, 0);
    Vec3 x0(0, 0, 0);
    float dt = 0.1f;

    // a = F/m
    float a = F.x / m;

    // semi-implicite: on update v d'abord puis x avec v nouveau
    float v1 = v0.x + a * dt;
    float x1 = x0.x + v1 * dt;  // utilise v1 pas v0

    cout << "v1 = " << v1 << " m/s" << endl;
    cout << "x1 = " << x1 << " m" << endl;
    cout << endl;
}

//===========================================
// Exercice 3 : Acceleration variable
// a(t) = 3t, x0=0, v0=0, dt=0.5s
//===========================================
void Exo3_AccelVariable()
{
    cout << "=== Exo 3 : Accel Variable ===" << endl;

    float v0 = 0;
    float x0 = 0;
    float dt = 0.5f;
    float t0 = 0;

    // a(t) = 3*t -> a0 = 3*0 = 0
    float a0 = 3.0f * t0;

    // euler explicite
    float v1 = v0 + a0 * dt;
    float x1 = x0 + v0 * dt;

    cout << "a0 = " << a0 << " m/s2" << endl;
    cout << "v1 = " << v1 << " m/s" << endl;
    cout << "x1 = " << x1 << " m" << endl;
    // les deux sont 0 car a(0)=0 et v0=0
    cout << endl;
}

//===========================================
// Exercice 4 : Ressort simple
// m=1kg, k=20N/m, x0=0.1m, v0=0, dt=0.05s
// methode Verlet ou symplectique
//===========================================
void Exo4_Ressort()
{
    cout << "=== Exo 4 : Ressort ===" << endl;

    float m = 1.0f;
    float k = 20.0f;
    float x0 = 0.1f;
    float v0 = 0;
    float dt = 0.05f;

    // F = -kx -> a = -k/m * x
    float a0 = -(k / m) * x0;

    // euler semi-implicite (symplectique)
    float v1 = v0 + a0 * dt;
    float x1 = x0 + v1 * dt;

    cout << "a0 = " << a0 << " m/s2" << endl;
    cout << "v1 = " << v1 << " m/s" << endl;
    cout << "x1 = " << x1 << " m" << endl;
    cout << endl;
}



int main()
{
    cout << "========================================" << endl;
    cout << "   Section 10.7 - Integrateurs Num     " << endl;
    cout << "========================================" << endl;
    cout << endl;

    Exo1_EulerExplicite();
    Exo2_EulerSemiImplicite();
    Exo3_AccelVariable();
    Exo4_Ressort();

    return 0;
}
