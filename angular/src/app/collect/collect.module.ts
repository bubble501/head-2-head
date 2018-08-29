import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { CollectRoutingModule } from './collect-routing.module';
import { CollectHolderComponent } from './components/collect-holder.component';

@NgModule({
  imports: [
    CommonModule,
    CollectRoutingModule
  ],
  declarations: [
    CollectHolderComponent
  ],
  exports: [
    CollectRoutingModule
  ]
})
export class CollectModule { }
