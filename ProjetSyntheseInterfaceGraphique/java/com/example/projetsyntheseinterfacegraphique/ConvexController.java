package com.example.projetsyntheseinterfacegraphique;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.Point2D;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

import static java.lang.String.valueOf;

public class ConvexController {

    ArrayList<Circle> points = new ArrayList<Circle>();
    @FXML
    private Pane pane;

    @FXML
    public void initialize(){
        pane.addEventHandler(MouseEvent.MOUSE_PRESSED, new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                if(mouseEvent.isPrimaryButtonDown()){
                    Point2D PHG = new Point2D(mouseEvent.getX(), mouseEvent.getY());
                    Circle c = new Circle(PHG.getX(), PHG.getY(), 3);
                    pane.getChildren().add(c);
                    points.add(c);
                }
            }
        });
    }
    @FXML
    public void choisirFichier(ActionEvent event){
        FileChooser fileChooser = new FileChooser();

        fileChooser.setTitle("Choisir un fichier contenant des points");

        File homeDir = new File("C:\\");
        fileChooser.setInitialDirectory(homeDir);

        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Text Files", "*.txt"),
                new FileChooser.ExtensionFilter("Csv files", "*.csv")
        );

        File selectedFile = fileChooser.showOpenDialog(new Stage());
        if (selectedFile != null){
            try{
                try(BufferedReader reader = new BufferedReader(new FileReader(selectedFile))){
                    String line;
                    reader.readLine();
                    while((line = reader.readLine()) != null){
                        String[] words = line.split(" ");
                        Circle circle = new Circle(Double.parseDouble(words[0]), Double.parseDouble(words[1]),3);
                        pane.getChildren().add(circle);
                    }
                }
            }
            catch (Exception e){
                System.err.println("Erreur : impossible d'utiliser le fichier");
            }
        }
    }

    @FXML
    public void reintialiser(ActionEvent event){
        pane.getChildren().clear();
    }

    @FXML
    public void enregistrer(ActionEvent event) throws IOException {
        FileChooser fileChooser = new FileChooser();

        fileChooser.setTitle("Enregistrer un fichier contenant des points");

        File homeDir = new File("C:\\");
        fileChooser.setInitialDirectory(homeDir);

        File file = fileChooser.showSaveDialog(new Stage());

        Writer writer = new FileWriter(file, StandardCharsets.UTF_8);
        BufferedWriter bufferedWriter = new BufferedWriter(writer, points.size());

        bufferedWriter.write(valueOf(points.size()));
        bufferedWriter.newLine();

        for(int i = 0; i < points.size(); i++){
            bufferedWriter.write(Math.round(points.get(i).getCenterX()) + " " + Math.round(points.get(i).getCenterY()));
            bufferedWriter.newLine();
        }
        bufferedWriter.close();

    }


}