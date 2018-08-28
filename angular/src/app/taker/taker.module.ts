import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { TakerHolderComponent } from './components/taker-holder.component';
import {TakerRoutingModule} from './taker-routing.module';

@NgModule({
  imports: [
    CommonModule,
    TakerRoutingModule
  ],
  declarations: [
    TakerHolderComponent
  ],
  exports: [
    TakerRoutingModule
  ]
})
export class TakerModule { }
