import 'package:flutter/material.dart';
import 'package:qr_reader/models/scan_model.dart';

import 'package:qr_reader/pages/direcciones_page.dart';
import 'package:qr_reader/pages/mapas_page.dart';

import 'package:provider/provider.dart';
import 'package:qr_reader/providers/db_provider.dart';
import 'package:qr_reader/providers/scan_list_provider.dart';
import 'package:qr_reader/providers/ui_provider.dart';

import 'package:qr_reader/widgets/custom_navigatorbar.dart';
import 'package:qr_reader/widgets/scan_button.dart';


class HomePage extends StatelessWidget {
  
  @override
  Widget build(BuildContext context) {
    return  Scaffold(
      appBar: AppBar(
        elevation: 0,
        title: const Text('Historial'),
        actions: [
          IconButton(
            icon: const Icon(Icons.delete_forever),
            onPressed: (){
              
              Provider.of<ScanListProvider>(context, listen: false).borrarTodos();

            }, 
            )
        ]
        ),
      body: _HomePageBody(),

      bottomNavigationBar: CustomNavigationBar() ,
      floatingActionButton: ScanButton(),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,

    );
  }
}


class _HomePageBody extends StatelessWidget {

  @override
  Widget build(BuildContext context) {

    final uiProvider = Provider.of<UiProvider>(context);

    //cambiar para mostrar la pg
    final currentIndex = uiProvider.selectedMenuOpt;

    //Usar el ScanListProvider
    final scanListProvider = Provider.of<ScanListProvider>(context, listen: false);

    
    switch( currentIndex ){

      case 0:
        scanListProvider.cargarScansPorTipo('geo');
        return MapasPage();
        break;

      case 1:
      scanListProvider.cargarScansPorTipo('http');
        return DireccionesPage();
        break;

      default: 
        return MapasPage();
    }
  }
}