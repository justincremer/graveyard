import 'dart:html';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'dart:html';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Just some pictures really...'),
          backgroundColor: Colors.black87,
        ),
        body: Center(
          child: SingleChildScrollView(
            padding: EdgeInsets.all(15.0),
            child: Column(
              children: <Widget>[
                Image.asset('assets/images/dds.jpg'),
                Text('\npicture 1\n'),
                Image.asset('assets/images/hypnagogia.jpg'),
                Text('\npicture 2\n'),
                Image.asset('assets/images/twin_peaks.jpg'),
                Text('\npicture 3'),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
