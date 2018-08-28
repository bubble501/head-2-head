import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';

import { MakerRoutingModule } from './maker-routing.module';
import { MakerHolderComponent } from './components/maker-holder.component';

@NgModule({
  imports: [
    CommonModule,
    MakerRoutingModule
  ],
  declarations: [
    MakerHolderComponent
  ],
  exports: [
    MakerRoutingModule,
    MakerHolderComponent
  ]
})
export class MakerModule { }
