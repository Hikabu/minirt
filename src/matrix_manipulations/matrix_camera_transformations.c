#include "minirt.h"

void multiplyMatrices(float result[4][4], float mat1[4][4], float mat2[4][4]) {
    int i = 0, j, k;
    float temp[4][4];

    while (i < 4) {
        j = 0;
        while (j < 4) {
            temp[i][j] = 0;
            k = 0;
            while (k < 4) {
                temp[i][j] += mat1[i][k] * mat2[k][j];
                k++;
            }
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 4) {
        j = 0;
        while (j < 4) {
            result[i][j] = temp[i][j];
            j++;
        }
        i++;
    }
}

void updateCameraPosition(t_camera *camera, float dx, float dy, float dz) {
    float translationMatrix[4][4];
    createTranslationMatrix(translationMatrix, dx, dy, dz);
    
    // Assuming your camera position is stored as a vector, you can apply the transformation like this:
    float cameraPos[4] = {camera->xyz.x, camera->xyz.y, camera->xyz.z, 1.0}; // Homogeneous coordinates
    float transformedPos[4] = {0};

    // Matrix-vector multiplication (could be a separate function)
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            transformedPos[i] += translationMatrix[i][j] * cameraPos[j];
        }
    }

    // Update camera position
    camera->xyz.x = transformedPos[0];
    camera->xyz.y = transformedPos[1];
    camera->xyz.z = transformedPos[2];
}

void createRotationMatrixY(float matrix[4][4], float angle) {
    float rad = angle * M_PI / 180.0; // Convert angle to radians

    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            matrix[i][j] = 0; 
            j++;
        }
        i++;
    }

    // Setting up the rotation matrix
    matrix[0][0] = cos(rad);
    matrix[0][2] = sin(rad);
    matrix[1][1] = 1; // Identity value
    matrix[2][0] = -sin(rad);
    matrix[2][2] = cos(rad);
    matrix[3][3] = 1; // Identity value for homogeneous coordinates
}

void createScalingMatrix(float matrix[4][4], float sx, float sy, float sz) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }

    // Directly set scaling values
    matrix[0][0] = sx;
    matrix[1][1] = sy;
    matrix[2][2] = sz;
    matrix[3][3] = 1; // Identity value for homogeneous coordinates
}

void createTranslationMatrix(float matrix[4][4], float tx, float ty, float tz) {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }

    // Set up the translation matrix
    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    matrix[3][3] = 1; // setting diagonal to 1 for identity
    matrix[0][3] = tx;
    matrix[1][3] = ty;
    matrix[2][3] = tz;
}

void rotateObject(t_sphere *sphere, float angle) {
    float rotationMatrix[4][4];
    createRotationMatrixY(rotationMatrix, angle);
    
    // Apply rotation to the sphere's center point
    float spherePos[4] = {sphere->xyz.x, sphere->xyz.y, sphere->xyz.z, 1.0}; // Homogeneous coordinates
    float transformedPos[4] = {0};

    // Matrix-vector multiplication (could be a separate function)
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            transformedPos[i] += rotationMatrix[i][j] * spherePos[j];
        }
    }

    sphere->xyz.x = transformedPos[0];
    sphere->xyz.y = transformedPos[1];
    sphere->xyz.z = transformedPos[2];
}


int key_press(int keycode, t_ent *data) {
    float dx = 0, dy = 0, dz = 0;

    if (keycode == 65307) { // ESC key for quitting
        mlx_destroy_window(data->mlx, data->window);
        exit(0);
    } else if (keycode == 119) { // 'W' key for moving forward
        dz = -1;
    } else if (keycode == 115) { // 'S' key for moving backward
        dz = 1;
    } else if (keycode == 97) { // 'A' key for moving left
        dx = -1;
    } else if (keycode == 100) { // 'D' key for moving right
        dx = 1;
    } else if (keycode == 113) { // 'Q' key for moving up
        dy = 1;
    } else if (keycode == 101) { // 'E' key for moving down
        dy = -1;
    }

    if (dx != 0 || dy != 0 || dz != 0) {
        // Assuming you have a function to update the camera position based on dx, dy, dz
        updateCameraPosition(data->scene->camera, dx, dy, dz);
        // Redraw your scene here as the camera position has changed
        mlx_clear_window(data->mlx, data->window); // Clear the previous content
        ray_trace(data); // Re-draw your scene with the updated camera position
    }

    return 0; // Return 0 to indicate success
}
