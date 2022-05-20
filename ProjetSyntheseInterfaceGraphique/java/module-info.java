module com.example.projetsyntheseinterfacegraphique {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires validatorfx;

    opens com.example.projetsyntheseinterfacegraphique to javafx.fxml;
    exports com.example.projetsyntheseinterfacegraphique;
}