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

//===========================================
// Exercice 5 : Gravite + frottement
// m=2kg, Fdrag=-0.5v, g=9.81, v0=0, y0=10m
//===========================================
void Exo5_GraviteFrottement()
{
    cout << "=== Exo 5 : Gravite + Frottement ===" << endl;

    float m = 2.0f;
    float g = 9.81f;
    float b = 0.5f;  // coef drag
    float v0 = 0;
    float y0 = 10.0f;
    float dt = 0.1f;

    // a = g - (b/m)*v  (vers le bas positif ici)
    float a = g - (b / m) * v0;

    // euler explicite
    float v1 = v0 + a * dt;
    float y1 = y0 - v1 * dt;  // - car on descend

    cout << "a = " << a << " m/s2" << endl;
    cout << "v1 = " << v1 << " m/s" << endl;
    cout << "y1 = " << y1 << " m" << endl;
    cout << endl;
}

//===========================================
// Exercice 6 : Projectile simple
// v0=10m/s horizontal, y0=5m, g=9.81, dt=0.2s
//===========================================
void Exo6_Projectile()
{
    cout << "=== Exo 6 : Projectile ===" << endl;

    float vx0 = 10.0f;
    float vy0 = 0;
    float x0 = 0;
    float y0 = 5.0f;
    float g = 9.81f;
    float dt = 0.2f;

    // euler semi-implicite
    // update vy d'abord
    float vy1 = vy0 - g * dt;
    float vx1 = vx0;  // pas de force horizontale

    float x1 = x0 + vx1 * dt;
    float y1 = y0 + vy1 * dt;

    cout << "vx1 = " << vx1 << " m/s" << endl;
    cout << "vy1 = " << vy1 << " m/s" << endl;
    cout << "x1 = " << x1 << " m" << endl;
    cout << "y1 = " << y1 << " m" << endl;
    cout << endl;
}

//===========================================
// Exercice 7 : Forces combinees
// m=1kg, Fx=4N, Fy=3N, dt=0.1s
//===========================================
void Exo7_ForcesCombinees()
{
    cout << "=== Exo 7 : Forces Combinees ===" << endl;

    float m = 1.0f;
    float Fx = 4.0f;
    float Fy = 3.0f;
    float dt = 0.1f;

    float vx0 = 0, vy0 = 0;
    float x0 = 0, y0 = 0;

    float ax = Fx / m;
    float ay = Fy / m;

    // euler explicite
    float vx1 = vx0 + ax * dt;
    float vy1 = vy0 + ay * dt;
    float x1 = x0 + vx0 * dt;
    float y1 = y0 + vy0 * dt;

    cout << "vx = " << vx1 << ", vy = " << vy1 << " m/s" << endl;
    cout << "x1 = " << x1 << ", y1 = " << y1 << " m" << endl;
    cout << endl;
}

//===========================================
// Exercice 8 : Accel fonction de position
// a = -2x (ressort ideal, m=1)
// x0=0.2, v0=0, dt=0.1s
//===========================================
void Exo8_AccelPosition()
{
    cout << "=== Exo 8 : Accel f(position) ===" << endl;

    float x0 = 0.2f;
    float v0 = 0;
    float dt = 0.1f;

    // a = -2x
    float a0 = -2.0f * x0;

    // euler semi-implicite
    float v1 = v0 + a0 * dt;
    float x1 = x0 + v1 * dt;

    cout << "a0 = " << a0 << endl;
    cout << "v1 = " << v1 << " m/s" << endl;
    cout << "x1 = " << x1 << " m" << endl;
    cout << endl;
}

//===========================================
// Exercice 9 : Collision elastique
// 2 objets m=1, v1=2m/s, v2=-1m/s
//===========================================
void Exo9_CollisionElastique()
{
    cout << "=== Exo 9 : Collision Elastique ===" << endl;

    float m1 = 1.0f, m2 = 1.0f;
    float v1i = 2.0f;
    float v2i = -1.0f;

    // masses identiques -> echange de vitesses
    float v1f = v2i;
    float v2f = v1i;

    cout << "Avant: v1=" << v1i << ", v2=" << v2i << endl;
    cout << "Apres: v1=" << v1f << ", v2=" << v2f << endl;
    cout << endl;
}

//===========================================
// Exercice 10 : Comparaison integrateurs
// F=10N, m=1kg, total 1s, dt=0.1s
//===========================================
void Exo10_Comparaison()
{
    cout << "=== Exo 10 : Comparaison Integrateurs ===" << endl;

    float F = 10.0f;
    float m = 1.0f;
    float a = F / m;  // 10 m/s2
    float dt = 0.1f;
    int steps = 10;   // 1s total

    // Euler explicite
    float v_euler = 0, x_euler = 0;
    for (int i = 0; i < steps; i++)
    {
        x_euler += v_euler * dt;
        v_euler += a * dt;
    }

    // Euler semi-implicite
    float v_semi = 0, x_semi = 0;
    for (int i = 0; i < steps; i++)
    {
        v_semi += a * dt;
        x_semi += v_semi * dt;
    }

    // Verlet (besoin de x_prev)
    float x_verlet = 0;
    float x_prev = 0;  // position precedente
    float v_verlet = 0;
    // premier pas special
    x_verlet = x_prev + v_verlet * dt + 0.5f * a * dt * dt;
    for (int i = 1; i < steps; i++)
    {
        float x_new = 2 * x_verlet - x_prev + a * dt * dt;
        x_prev = x_verlet;
        x_verlet = x_new;
    }

    cout << "Euler explicite: x = " << x_euler << " m" << endl;
    cout << "Euler semi-imp:  x = " << x_semi << " m" << endl;
    cout << "Verlet:          x = " << x_verlet << " m" << endl;
    cout << "(theorique: x = 0.5*a*t^2 = 5m)" << endl;
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
    Exo5_GraviteFrottement();
    Exo6_Projectile();
    Exo7_ForcesCombinees();
    Exo8_AccelPosition();
    Exo9_CollisionElastique();
    Exo10_Comparaison();

    return 0;
}
