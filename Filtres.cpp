#include "Filtres.h"
#include <opencv2/opencv.hpp>
int Filtres::canny()
{
    Mat imgOriginal;        // L'image de base
    Mat imgGrayscale;        // L'image en teinte de gris
    Mat imgBlurred;            // L'image intermediaire
    Mat imgCanny;            // Le résultat



    imgOriginal = imread("liberte2.jpg");            // On ouvre l'image

    if (imgOriginal.empty()) {                                    // On releve une excpetion
        std::cout << "error: ceci n'est pas une image\n\n";        // Message d'erreur
        return(0);                                                // on quitte le programme
    }

    cvtColor(imgOriginal, imgGrayscale, COLOR_BGR2GRAY);        // on convertit en teinte de gris

    GaussianBlur(imgGrayscale,            
        imgBlurred,                           
        cv::Size(5, 5),                        
        1.5);                                

    Canny(imgBlurred,           
        imgCanny,                    
        100,                        
        200);                       


    
    namedWindow("Image original", WINDOW_AUTOSIZE);
    namedWindow("Image filtre", WINDOW_AUTOSIZE);

    //Show windows
    imshow("Image original", imgOriginal);
    imshow("Image filtre", imgCanny);

    cv::waitKey(0);                    // On garde l'image ouverte tant que on a pas appuyer sur un boutton.
    return 0;
}

int Filtres::median()
{
    namedWindow("Image original", WINDOW_AUTOSIZE);

    // chargement de l'image de base
    Mat src = imread("liberte2.jpg", 1);

 // on crée la variable dst qui servira pour l'image transformé
    Mat dst;

    // on affiche l'image
    imshow("Image original", src);


    // on applique le filtre
    medianBlur(src, dst, 3);

    // et on affiche le résultat
    imshow("Filtre median", dst);

    waitKey(0);
    return 0;
}

int Filtres::gaussien()
{// On lit l'image
    Mat image = imread("liberte2.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "ERREUR" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

   

    //On applique le filtres et on nomme les pages
    Mat image_blurred_with_5x5_kernel;
    GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

    
    String window_name = "Image Original";
   
    String window_name_blurred_with_5x5_kernel = "Image filtre";

    // Là on crée les pages d'images
    namedWindow(window_name);
   
    namedWindow(window_name_blurred_with_5x5_kernel);

    // Et on montre les images
    imshow(window_name, image);
    
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.

    destroyAllWindows(); //On détruit toutes les pages

    return 0;
}

int Filtres::dilatation()
{
    //chargement de l'image classique
    Mat img = imread("liberte2.jpg");
    // on regarde si il y a un échec
    if (img.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //appuyer sur une touche
        return -1;
    }
    namedWindow("Image original");
    imshow("Image original", img);


    Mat dila;
    //dilate and display the dilated image
    dilate(img, dila, getStructuringElement(MORPH_RECT, Size(3, 3)));
    namedWindow("Dilaté");
    imshow("Dilaté", dila);

    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.

    //destruction des fenêtres
    destroyAllWindows();

    return 0;
}

int Filtres::erosion()
{
    // Lecture de l'image à filtrer.
        Mat image = imread("liberte2.jpg");

    //On regarde si il y a une erreur
    if (image.empty())
    {
        cout << "ERREUR" << endl;
        cin.get(); // On attends l'input de n'importe quelle touche
        return -1;
    }

    

    //On applique le filtres. 
    Mat image_eroded_with_5x5_kernel;
    erode(image, image_eroded_with_5x5_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

    //On défini le nom des pages contenant les images.
    String window_name = "Liberté";
   
    String window_name_eroded_with_5x5_kernel = "Liberté érosé";

    // On crée les pages
    namedWindow(window_name);
   
    namedWindow(window_name_eroded_with_5x5_kernel);

    // On montres les images.
    imshow(window_name, image);
   
    imshow(window_name_eroded_with_5x5_kernel, image_eroded_with_5x5_kernel);

    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.

    destroyAllWindows(); // On détruit toute les pages 

    return 0;
}

int Filtres::grad()
{   // On crée l'image original et on crée la deuxième qui contiendra l'image filtré.
    Mat img = imread("liberte2.jpg");
    Mat img_simple_blur, img_bulr_no_scale, img_blur_median, img_blur_gauss, img_blur_bilateral;
    //On lis l'image original
    namedWindow("Image original", 0);
    imshow("Image original", img);
    // On crée l'image filtré
    namedWindow("Image filtre", 0);
    Sobel(img, img, 0, 2, 1);
    // On montre l'image
    imshow("Image filtre", img);
    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.
    return 0;
}

int Filtres::seuillages()
{ // On affecte aux images leurs emplacements
    Mat img = imread("liberte2.jpg");
    Mat gray_img;
    //Filtrage en niveaux de gris.
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    // Masque binaire
    Mat binary;
    threshold(gray_img, binary, 100, 255, THRESH_BINARY);
    // On tronque de manière à avoir l'image filtre
    Mat truncate;
    threshold(gray_img, truncate, 150, 150, THRESH_TRUNC);
    // On montre le seuillages.
    imshow("Image original", img);
    imshow("Image grise", gray_img);
    imshow("Binaire", binary);
    imshow("tronque", truncate);

    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.
    return 0;
}

int Filtres::croissance_region()
{// On crée les emplacements des images filtré et original
    Mat org_img = imread("liberte2.jpg");
    Mat gray_img, op_img;
    // On filtre l'image
    cvtColor(org_img, gray_img, COLOR_BGR2GRAY);
    threshold(gray_img, op_img, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // On montre les images.
    imshow("Image original", org_img);
    imshow("Image final", op_img);
    adaptiveThreshold(gray_img, op_img, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 11);
    waitKey(0); // On garde l'image ouverte tant que on a pas appuyer sur un boutton.
    return 0;

}
