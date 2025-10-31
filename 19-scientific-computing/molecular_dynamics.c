#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PARTICLES 10
#define BOX_SIZE 10.0
#define DT 0.001
#define NUM_STEPS 1000
#define MIN_DISTANCE 0.0001  // Minimum distance to avoid division by zero

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
    double mass;
} Particle;

// Initialize particles
void initParticles(Particle particles[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        particles[i].x = ((double)rand() / RAND_MAX) * BOX_SIZE;
        particles[i].y = ((double)rand() / RAND_MAX) * BOX_SIZE;
        particles[i].z = ((double)rand() / RAND_MAX) * BOX_SIZE;
        particles[i].vx = ((double)rand() / RAND_MAX - 0.5) * 2.0;
        particles[i].vy = ((double)rand() / RAND_MAX - 0.5) * 2.0;
        particles[i].vz = ((double)rand() / RAND_MAX - 0.5) * 2.0;
        particles[i].mass = 1.0;
    }
}

// Calculate Lennard-Jones forces
void calculateForces(Particle particles[], int n) {
    double epsilon = 1.0;
    double sigma = 1.0;
    double cutoff = 2.5;
    
    // Reset forces
    for (int i = 0; i < n; i++) {
        particles[i].fx = 0.0;
        particles[i].fy = 0.0;
        particles[i].fz = 0.0;
    }
    
    // Calculate pairwise forces
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = particles[i].x - particles[j].x;
            double dy = particles[i].y - particles[j].y;
            double dz = particles[i].z - particles[j].z;
            
            // Periodic boundaries
            dx -= BOX_SIZE * round(dx / BOX_SIZE);
            dy -= BOX_SIZE * round(dy / BOX_SIZE);
            dz -= BOX_SIZE * round(dz / BOX_SIZE);
            
            double r2 = dx*dx + dy*dy + dz*dz;
            
            if (r2 < cutoff * cutoff && r2 > MIN_DISTANCE) {
                double r2inv = sigma * sigma / r2;
                double r6inv = r2inv * r2inv * r2inv;
                double force = 24.0 * epsilon * r6inv * (2.0 * r6inv - 1.0) / r2;
                
                particles[i].fx += force * dx;
                particles[i].fy += force * dy;
                particles[i].fz += force * dz;
                
                particles[j].fx -= force * dx;
                particles[j].fy -= force * dy;
                particles[j].fz -= force * dz;
            }
        }
    }
}

// Update positions and velocities
void velocityVerlet(Particle particles[], int n, double dt) {
    // Update velocities (half step) and positions
    for (int i = 0; i < n; i++) {
        particles[i].vx += 0.5 * (particles[i].fx / particles[i].mass) * dt;
        particles[i].vy += 0.5 * (particles[i].fy / particles[i].mass) * dt;
        particles[i].vz += 0.5 * (particles[i].fz / particles[i].mass) * dt;
        
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;
        particles[i].z += particles[i].vz * dt;
        
        // Periodic boundaries
        particles[i].x = fmod(particles[i].x + BOX_SIZE, BOX_SIZE);
        particles[i].y = fmod(particles[i].y + BOX_SIZE, BOX_SIZE);
        particles[i].z = fmod(particles[i].z + BOX_SIZE, BOX_SIZE);
        if (particles[i].x < 0) particles[i].x += BOX_SIZE;
        if (particles[i].y < 0) particles[i].y += BOX_SIZE;
        if (particles[i].z < 0) particles[i].z += BOX_SIZE;
    }
    
    // Calculate new forces
    calculateForces(particles, n);
    
    // Update velocities (second half step)
    for (int i = 0; i < n; i++) {
        particles[i].vx += 0.5 * (particles[i].fx / particles[i].mass) * dt;
        particles[i].vy += 0.5 * (particles[i].fy / particles[i].mass) * dt;
        particles[i].vz += 0.5 * (particles[i].fz / particles[i].mass) * dt;
    }
}

// Calculate kinetic energy
double calculateKineticEnergy(Particle particles[], int n) {
    double ke = 0.0;
    for (int i = 0; i < n; i++) {
        double v2 = particles[i].vx*particles[i].vx + 
                    particles[i].vy*particles[i].vy + 
                    particles[i].vz*particles[i].vz;
        ke += 0.5 * particles[i].mass * v2;
    }
    return ke;
}

int main() {
    printf("=== Simple Molecular Dynamics Simulation ===\n\n");
    printf("Particles: %d\n", NUM_PARTICLES);
    printf("Box size: %.2f\n", BOX_SIZE);
    printf("Time step: %.4f\n", DT);
    printf("Steps: %d\n\n", NUM_STEPS);
    
    Particle particles[NUM_PARTICLES];
    initParticles(particles, NUM_PARTICLES);
    
    // Initial forces
    calculateForces(particles, NUM_PARTICLES);
    
    printf("Running simulation...\n");
    
    // Main simulation loop
    for (int step = 0; step < NUM_STEPS; step++) {
        velocityVerlet(particles, NUM_PARTICLES, DT);
        
        if (step % 100 == 0) {
            double ke = calculateKineticEnergy(particles, NUM_PARTICLES);
            double temp = 2.0 * ke / (3.0 * NUM_PARTICLES);
            printf("Step %4d: KE = %.4f, T = %.4f\n", step, ke, temp);
        }
    }
    
    printf("\nSimulation complete!\n");
    printf("Final particle positions:\n");
    for (int i = 0; i < NUM_PARTICLES && i < 5; i++) {
        printf("Particle %d: (%.2f, %.2f, %.2f)\n", 
               i, particles[i].x, particles[i].y, particles[i].z);
    }
    
    return 0;
}
