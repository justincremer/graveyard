import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    var singleChildScrollView = SingleChildScrollView(
              Center(
                child: Column(
                  children: [
                    child: Image(
                      image: NetworkImage(
                        'https://external-content.duckduckgo.com/iu/?u=http%3A%2F%2Fwww.anacortes.net%2Fwp-content%2Fuploads%2Flookingatmounteerie.jpg&f=1&nofb=1'
                      ),
                    ),
                    child: Image(
                      image: AssetImage('assets/images/dds.jpg'),
                    ),
                  ],
                ),
              ),
            );
            
        return MaterialApp(
          home: Scaffold(
            backgroundColor: Colors.blueGrey,
            appBar: AppBar(
              title: Text('Just a picture'),
              backgroundColor: Colors.blueGrey[900],
            ),
            body: singleChildScrollView,
      ),
    );
  }
}
